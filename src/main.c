/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:38:38 by lomeress          #+#    #+#             */
/*   Updated: 2019/03/11 13:31:42 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "libft.h"

t_mat4       g_matrix;
t_mat4       g_translation;
t_inputs     g_inputs;
float        g_delta_time;
GLint        g_which;
t_mat4       g_translation;
t_mat4       g_projection;

void	HandleTime()
{
	static float	lastFrame = 0.0f;
	float			currentFrame;
	static float	second = 0.0f;
	static int		fps = 0;

	currentFrame = glfwGetTime();
	g_delta_time = currentFrame - lastFrame;
	lastFrame = currentFrame;
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

int main(int ac, char **av)
{
	GLFWwindow	*window;
	GLuint		vaoID;
	GLuint		vboID;
	GLuint		iboID;
	GLuint		programID;
	GLuint		matriceID;

//here
	ac = 0;
	int ve;
 	int fe;

	ve = 0;
	fe = 0;

	t_obj obj = parse(av[1], &ve, &fe);
/*	if(ac == 0 || ac > 2)
	{
		obj = parse("../../../Downloads/resources/42.obj", &ve, &fe);
	}*/

	const GLfloat *v = obj.vertex;
	const GLuint *f = obj.indices;
	g_matrix = scaling_matrix(1.0f);
	g_translation = translation_matrix(0.0f, 0.0f, -5.0f);
	g_projection = projection_matrix();

	if (!glfwInit())
	{
		ft_putendl("ERROR: could not start GLFW3");
		exit(0);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	window = glfwCreateWindow(W, H, "scop", NULL, NULL);
	if (!window)
	{
		ft_putendl("ERROR: could not open window with GLFW3");
		exit(0);
	}
	glfwMakeContextCurrent(window);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_MULTISAMPLE);
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	programID = create_program(create_shader("shaders/fragment.glsl", GL_FRAGMENT_SHADER), create_shader("shaders/vertex.glsl", GL_VERTEX_SHADER));
	
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, ve * sizeof(GLfloat), v, GL_STATIC_DRAW);
	
	glGenBuffers(1, &iboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, fe * sizeof(GLfloat), f, GL_STATIC_DRAW);
	
	matriceID = glGetUniformLocation(programID, "mvp");

	glfwSetKeyCallback(window, key_callback);

	while (glfwWindowShouldClose(window) == 0 && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		events();
		HandleTime();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);

		glUniformMatrix4fv(matriceID, 1, GL_FALSE, matrix_matrix_mul(matrix_matrix_mul(g_matrix, g_translation), g_projection).m);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawElements(GL_TRIANGLES, fe, GL_UNSIGNED_INT, NULL);
		glDisableVertexAttribArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteBuffers(1, &vboID);
	glDeleteBuffers(1, &iboID);
	glDeleteVertexArrays(1, &vaoID);
	glDeleteProgram(programID);
	glfwTerminate();

	return (0);
}
