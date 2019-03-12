/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:24:19 by lomeress          #+#    #+#             */
/*   Updated: 2019/03/12 21:24:35 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <stdlib.h>
# include <GLFW/glfw3.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/libft/include/libft.h"
# include <math.h>

# define FOV 45
# define W 1280
# define H 1280

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_mat4
{
	float			m[16];
}					t_mat4;

typedef struct		s_loadbmp
{
	unsigned char	header[54];
	unsigned int	datapos;
	unsigned int	width;
	unsigned int	height;
	unsigned int	image_size;
	unsigned char	*data;
}					t_loadbmp;

typedef struct		s_inputs
{
	short int		up;
	short int		down;
	short int		left;
	short int		right;
	short int		zoomin;
	short int		zoomout;
	short int		tup;
	short int		tdown;
	short int		tright;
	short int		tleft;
	short int		tfront;
	short int		tback;
	short int		intensityPLUS;
	short int		intensityMOINS;
}					t_inputs;

typedef struct		s_uvcalc
{
	float			min_x;
	float			min_y;
	float			max_x;
	float			max_y;
	float			k_x;
	float			k_y;
}					t_uvcalc;

typedef struct		s_maxmin
{
	float			max_x;
	float			max_y;
	float			min_x;
	float			min_y;
	float			max_z;
	float			min_z;
}					t_maxmin;

typedef struct		s_obj
{
	GLfloat			*vertex;
	GLuint			*indices;
	float			*uv;
	int				vsize;
	int				isize;
	int				uvsize;
}					t_obj;

typedef struct		s_uniforms
{
	GLint			matrix_id;
	GLint			which_id;
	GLuint			shader_programme;
}					t_uniforms;

typedef struct		s_buffer_objects
{
	GLuint			vbo;
	GLuint			tbo;
	GLuint			ibo;
	GLuint			vao;
}					t_buffer_objects;

typedef	struct		s_norm
{
	GLFWwindow      *window;
	GLuint          vaoid;
	GLuint          vboid;
	GLuint          iboid;
	GLuint          programid;
	GLuint          matriceid;
	int             ve;
	int             fe;
	GLfloat			*v;
	const GLuint    *f;
	t_obj           obj;
	GLuint          intensity;
	GLuint          textureoupasid;
	GLuint          texture_id;
}					t_norm;

extern t_mat4		g_matrix;
extern t_mat4		g_translation;
extern t_inputs		g_inputs;
extern float		g_delta_time;
extern GLint		g_which;
extern t_mat4		g_translation;
extern t_mat4		g_projection;
extern float		g_intensity;

GLuint				load_bmp(char *filename);
char				*load_file(char *filename);
GLuint				create_shader(char *filename, int shadertype);
GLuint				create_program(GLuint vertex, GLuint fragment);
t_mat4				scaling_matrix(float scale);
t_mat4				matrix_matrix_mul(t_mat4 m, t_mat4 n);
t_mat4				translation_matrix(float x, float y, float z);
t_mat4				projection_matrix(void);
t_mat4				rotation_matrix_z(float angle);
t_mat4				rotation_matrix_y(float angle);
t_mat4				rotation_matrix_x(float angle);
void				key_callback(GLFWwindow *window, int key, int scancode,
		int action, int mods);
void				events(void);
t_obj				parse(char *filename, int *v, int *f);
t_obj				center(t_obj obj);
void				center_obj(float **vertex, int size);

#endif
