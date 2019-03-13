/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:27:07 by lomeress          #+#    #+#             */
/*   Updated: 2019/03/13 11:37:46 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include "libft.h"

t_mat4			projection_matrix(void)
{
	t_mat4	projection;
	float	s;
	float	far;
	float	near;
	int		i;

	i = 0;
	while (i < 16)
		projection.m[i++] = 0.0f;
	far = 100.0f;
	near = 0.01f;
	s = 1 / (tan(FOV * 0.5 * M_PI / 180.0));
	projection.m[0] = s / ((float)W / (float)H);
	projection.m[5] = s;
	projection.m[10] = -(far + near) / (far - near);
	projection.m[11] = -1;
	projection.m[14] = -2 * far * near / (far - near);
	return (projection);
}

t_mat4			translation_matrix(float x, float y, float z)
{
	t_mat4	mat;
	int		i;

	i = 0;
	while (i < 16)
		mat.m[i++] = 0.0f;
	mat.m[0] = 1.0f;
	mat.m[5] = 1.0f;
	mat.m[10] = 1.0f;
	mat.m[12] = x;
	mat.m[13] = y;
	mat.m[14] = z;
	mat.m[15] = 1.0f;
	return (mat);
}

t_mat4			matrix_matrix_mul(t_mat4 m, t_mat4 n)
{
	t_mat4	result;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			result.m[i * 4 + j] = 0.0f;
			while (k < 4)
			{
				result.m[i * 4 + j] += m.m[i * 4 + k] * n.m[k * 4 + j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

t_mat4			scaling_matrix(float scale)
{
	t_mat4	mat;
	int		i;

	i = 0;
	while (i < 16)
		mat.m[i++] = 0.0f;
	mat.m[0] = scale;
	mat.m[5] = scale;
	mat.m[10] = scale;
	mat.m[15] = 1.0f;
	return (mat);
}
