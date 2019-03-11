/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:20:31 by lomeress          #+#    #+#             */
/*   Updated: 2019/03/11 12:07:34 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "libft.h"

t_mat4	rotation_matrix_x(float angle)
{
	t_mat4	rot;
	int		i;

	i = 0;
	while (i < 16)
		rot.m[i++] = 0.0f;
	rot.m[0] = 1.0f;
	rot.m[5] = cos(angle);
	rot.m[6] = -sin(angle);
	rot.m[9] = sin(angle);
	rot.m[10] = cos(angle);
	rot.m[15] = 1.0f;
	return (rot);
}

t_mat4	rotation_matrix_y(float angle)
{
	t_mat4	rot;
	int		i;

	i = 0;
	while (i < 16)
		rot.m[i++] = 0.0f;
	rot.m[0] = cos(angle);
	rot.m[2] = sin(angle);
	rot.m[5] = 1.0f;
	rot.m[8] = -sin(angle);
	rot.m[10] = cos(angle);
	rot.m[15] = 1.0f;
	return (rot);
}

t_mat4	rotation_matrix_z(float angle)
{
	t_mat4	rot;
	int		i;

	i = 0;
	while (i < 16)
		rot.m[i++] = 0.0f;
	rot.m[0] = cos(angle);
	rot.m[1] = -sin(angle);
	rot.m[4] = sin(angle);
	rot.m[5] = cos(angle);
	rot.m[10] = 1.0f;
	rot.m[15] = 1.0f;
	return (rot);
}
