/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:09:48 by lomeress          #+#    #+#             */
/*   Updated: 2019/03/12 20:51:54 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_inputs	g_inputs;

static void	key_callback3(GLFWwindow *window, int key, int scancode,
		int action, int mods)
{
	(void)window;
	(void)scancode;
	(void)mods;
	if (key == 334 && action == GLFW_PRESS)
		g_inputs.zoomin = 1;
	else if (key == 334 && action == GLFW_RELEASE)
		g_inputs.zoomin = 0;
	if (key == 333 && action == GLFW_PRESS)
		g_inputs.zoomout = 1;
	else if (key == 333 && action == GLFW_RELEASE)
		g_inputs.zoomout = 0;
	if (key == 320 && action == GLFW_PRESS)
		g_which = 0;
	else if (key == 321 && action == GLFW_PRESS)
		g_which = 1;
	else if (key == 322 && action == GLFW_PRESS)
		g_which = 2;
	else if (key == 323 && action == GLFW_PRESS)
		g_which = 3;
}

static void	key_callback2(GLFWwindow *window, int key, int scancode,
		int action, int mods)
{
	if (key == 87 && action == GLFW_PRESS)
		g_inputs.tup = 1;
	else if (key == 87 && action == GLFW_RELEASE)
		g_inputs.tup = 0;
	if (key == 83 && action == GLFW_PRESS)
		g_inputs.tdown = 1;
	else if (key == 83 && action == GLFW_RELEASE)
		g_inputs.tdown = 0;
	if (key == 65 && action == GLFW_PRESS)
		g_inputs.tleft = 1;
	else if (key == 65 && action == GLFW_RELEASE)
		g_inputs.tleft = 0;
	if (key == 68 && action == GLFW_PRESS)
		g_inputs.tright = 1;
	else if (key == 68 && action == GLFW_RELEASE)
		g_inputs.tright = 0;
	if (key == 81 && action == GLFW_PRESS)
		g_inputs.tback = 1;
	else if (key == 81 && action == GLFW_RELEASE)
		g_inputs.tback = 0;
	if (key == 69 && action == GLFW_PRESS)
		g_inputs.tfront = 1;
	else if (key == 69 && action == GLFW_RELEASE)
		g_inputs.tfront = 0;
	key_callback3(window, key, scancode, action, mods);
}

void		key_callback(GLFWwindow *window, int key, int scancode, int action,
				int mods)
{
	if (key == 265 && action == GLFW_PRESS)
		g_inputs.up = 1;
	else if (key == 265 && action == GLFW_RELEASE)
		g_inputs.up = 0;
	if (key == 262 && action == GLFW_PRESS)
		g_inputs.right = 1;
	else if (key == 262 && action == GLFW_RELEASE)
		g_inputs.right = 0;
	if (key == 264 && action == GLFW_PRESS)
		g_inputs.down = 1;
	else if (key == 264 && action == GLFW_RELEASE)
		g_inputs.down = 0;
	if (key == 263 && action == GLFW_PRESS)
		g_inputs.left = 1;
	else if (key == 263 && action == GLFW_RELEASE)
		g_inputs.left = 0;
	if (key == GLFW_KEY_B && action == GLFW_PRESS)
		g_inputs.intensityPLUS = 1;
	else if (key == GLFW_KEY_B && action == GLFW_RELEASE)
		g_inputs.intensityPLUS = 0;
	if (key == GLFW_KEY_N && action == GLFW_PRESS)
		g_inputs.intensityMOINS = 1;
	else if (key == GLFW_KEY_N && action == GLFW_RELEASE)
		g_inputs.intensityMOINS = 0;
	key_callback2(window, key, scancode, action, mods);
}

static void	events2(void)
{
	if (g_inputs.tup == 1)
		g_translation = matrix_matrix_mul(g_translation,
				translation_matrix(0.0f, 2.0f * g_delta_time, 0.0f));
	else if (g_inputs.tdown == 1)
		g_translation = matrix_matrix_mul(g_translation,
				translation_matrix(0.0f, -2.0f * g_delta_time, 0.0f));
	if (g_inputs.tright == 1)
		g_translation = matrix_matrix_mul(g_translation,
				translation_matrix(2.0f * g_delta_time, 0.0f, 0.0f));
	else if (g_inputs.tleft == 1)
		g_translation = matrix_matrix_mul(g_translation,
				translation_matrix(-2.0f * g_delta_time, 0.0f, 0.0f));
	if (g_inputs.tfront == 1)
		g_translation = matrix_matrix_mul(g_translation,
				translation_matrix(0.0f, 0.0f, -2.0f * g_delta_time));
	else if (g_inputs.tback == 1)
		g_translation = matrix_matrix_mul(g_translation,
				translation_matrix(0.0f, 0.0f, 2.0f * g_delta_time));
	if (g_inputs.intensityMOINS == 1 && g_intensity >= -0.95f)
		g_intensity -= 0.01f;
}

void		events(void)
{
	if (g_inputs.up == 1)
		g_matrix = matrix_matrix_mul(g_matrix, rotation_matrix_x(3.0f *
					g_delta_time));
	else if (g_inputs.down == 1)
		g_matrix = matrix_matrix_mul(g_matrix, rotation_matrix_x(-3.0f *
					g_delta_time));
	if (g_inputs.zoomout == 1)
		g_matrix = matrix_matrix_mul(g_matrix, scaling_matrix((1.0f -
						g_delta_time)));
	else if (g_inputs.zoomin == 1)
		g_matrix = matrix_matrix_mul(g_matrix, scaling_matrix((1.0f +
						g_delta_time)));
	if (g_inputs.right == 1)
		g_matrix = matrix_matrix_mul(g_matrix, rotation_matrix_y(-3.0f *
					g_delta_time));
	else if (g_inputs.left == 1)
		g_matrix = matrix_matrix_mul(g_matrix, rotation_matrix_y(3.0f *
					g_delta_time));
	else
		g_matrix = matrix_matrix_mul(g_matrix, rotation_matrix_y(-1.0f *
					g_delta_time));
	if (g_inputs.intensityPLUS == 1 && g_intensity <= 0.95f)
		g_intensity += 0.01f;
	events2();
}
