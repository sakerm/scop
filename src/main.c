/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:26:18 by lomeress          #+#    #+#             */
/*   Updated: 2019/03/13 18:45:41 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "libft.h"

t_mat4		g_matrix;
t_mat4		g_translation;
t_inputs	g_inputs;
float		g_delta_time;
GLint		g_which;
t_mat4		g_translation;
t_mat4		g_projection;
float		g_intensity;

void	handletime(void)
{
	static float	lastframe = 0.0f;
	float			currentframe;
	static float	second = 0.0f;
	static int		fps = 0;

	currentframe = glfwGetTime();
	g_delta_time = currentframe - lastframe;
	lastframe = currentframe;
	second += g_delta_time;
	fps++;
	if (second >= 1.0f)
	{
		second -= 1.0f;
		ft_putnbr(fps);
		ft_putchar('\n');
		fps = 0;
	}
}

t_norm	boucle(t_norm n)
{
	events();
	handletime();
	glClearColor(0.12f, 0.03f, 0.09f, 0.04f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(n.programid);
	glUniformMatrix4fv(n.matriceid, 1, GL_FALSE,
			matrix_matrix_mul(matrix_matrix_mul(g_matrix, g_translation),
				g_projection).m);
	glUniform1i(n.textureoupasid, g_which);
	glUniform1f(n.intensity, g_intensity);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, n.vboid);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawElements(GL_TRIANGLES, n.fe, GL_UNSIGNED_INT, NULL);
	glDisableVertexAttribArray(0);
	glfwSwapBuffers(n.window);
	glfwPollEvents();
	return (n);
}

t_norm	second_cut(t_norm n, t_obj *obj)
{
	n.window = glfwCreateWindow(W, H, "scop", NULL, NULL);
	if (!n.window)
		*obj = parse("./resources/error.obj", &n.ve, &n.fe);
	glfwMakeContextCurrent(n.window);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_MULTISAMPLE);
	glGenVertexArrays(1, &n.vaoid);
	glBindVertexArray(n.vaoid);
	n.programid = create_program(create_shader("shaders/fragment.glsl",
				GL_FRAGMENT_SHADER), create_shader("shaders/vertex.glsl",
					GL_VERTEX_SHADER));
	glGenBuffers(1, &n.vboid);
	glBindBuffer(GL_ARRAY_BUFFER, n.vboid);
	glBufferData(GL_ARRAY_BUFFER, n.ve * sizeof(GLfloat), n.v, GL_STATIC_DRAW);
	glGenBuffers(1, &n.iboid);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, n.iboid);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, n.fe * sizeof(GLfloat),
			n.f, GL_STATIC_DRAW);
	n.matriceid = glGetUniformLocation(n.programid, "mvp");
	n.textureoupasid = glGetUniformLocation(n.programid, "textureoupas");
	n.intensity = glGetUniformLocation(n.programid, "intensity");
	glfwSetKeyCallback(n.window, key_callback);
	n.texture_id = load_bmp("./texture/bois.bmp");
	return (n);
}

t_norm	first_cut(t_norm n, t_obj *obj, char **av)
{
	*obj = parse(av[1], &n.ve, &n.fe);
	n.f = obj->indices;
	n.v = obj->vertex;
	g_matrix = scaling_matrix(1.0f);
	g_translation = translation_matrix(0.0f, 0.0f, -5.0f);
	g_projection = projection_matrix();
	center_obj(&n.v, n.ve);
	if (!glfwInit())
		*obj = parse("./resources/error.obj", &n.ve, &n.fe);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	return (n);
}

int		main(int ac, char **av)
{
	t_norm	n;
	t_obj	obj;

	n.ve = 0;
	n.fe = 0;
	ac = 0;
	g_intensity = 0;
	n = first_cut(n, &obj, av);
	n = second_cut(n, &obj);
	if (open(av[1], O_RDWR) == -1)
		g_which = 1;
	while (glfwWindowShouldClose(n.window) == 0 && glfwGetKey(n.window,
				GLFW_KEY_ESCAPE) != GLFW_PRESS)
		n = boucle(n);
	glDeleteVertexArrays(1, &n.vaoid);
	glDeleteBuffers(1, &n.vboid);
	glDeleteBuffers(1, &n.iboid);
	glDeleteProgram(n.programid);
	glfwTerminate();
	return (0);
}
