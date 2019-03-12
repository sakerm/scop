/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:11:24 by lomeress          #+#    #+#             */
/*   Updated: 2019/03/12 16:29:46 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_maxmin	init_maxmin(void)
{
	t_maxmin	m;

	m.max_x = 0.0f;
	m.max_y = 0.0f;
	m.min_x = 0.0f;
	m.min_y = 0.0f;
	m.min_z = 0.0f;
	m.max_z = 0.0f;
	return (m);
}

t_maxmin	set_maxmin_and_scale(t_maxmin m, float *scale,
		float *vertices, int i)
{
	if (vertices[i] > m.max_x)
		m.max_x = vertices[i];
	if (vertices[i + 1] > m.max_y)
		m.max_y = vertices[i + 1];
	if (vertices[i] < m.min_x)
		m.min_x = vertices[i];
	if (vertices[i + 1] < m.min_y)
		m.min_y = vertices[i + 1];
	if (vertices[i + 2] < m.min_z)
		m.min_z = vertices[i + 2];
	if (vertices[i + 2] > m.max_z)
		m.max_z = vertices[i + 2];
	if (m.max_x > *scale)
		*scale = m.max_x;
	if (m.max_y > *scale)
		*scale = m.max_y;
	if (m.max_z > *scale)
		*scale = m.max_z;
	if (fabsf(m.min_x) > *scale)
		*scale = fabsf(m.min_x);
	if (fabsf(m.min_y) > *scale)
		*scale = fabsf(m.min_y);
	if (fabsf(m.min_z) > *scale)
		*scale = fabsf(m.min_z);
	return (m);
}

void		center_obj(float **vertex, int size)
{
	int			i;
	t_maxmin	m;
	float		*vertices;
	float		scale;

	i = 0;
	m = init_maxmin();
	scale = 0.0f;
	vertices = *vertex;
	while (i < size)
	{
		m = set_maxmin_and_scale(m, &scale, vertices, i);
		i += 3;
	}
	g_matrix = matrix_matrix_mul(g_matrix, scaling_matrix(0.60f / scale));
	i = 0;
	m.max_x = (m.min_x + m.max_x) / 2;
	m.max_y = (m.min_y + m.max_y) / 2;
	m.max_z = (m.min_z + m.max_z) / 2;
	while (i < size)
	{
		vertices[i++] -= m.max_x;
		vertices[i++] -= m.max_y;
		vertices[i++] -= m.max_z;
	}
}
