/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:50:07 by lomeress          #+#    #+#             */
/*   Updated: 2019/03/13 17:55:52 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLuint	load_bmp2(t_loadbmp l, int fd)
{
	t_norm n;

	l.datapos = *(int*)&(l.header[0x0A]);
	l.image_size = *(int*)&(l.header[0x22]);
	l.width = *(int*)&(l.header[0x12]);
	l.height = *(int*)&(l.header[0x16]);
	if (l.image_size == 0)
		l.image_size = l.width * l.height * 3;
	if (l.datapos == 0)
		l.datapos = 54;
	l.data = (unsigned char*)malloc(sizeof(unsigned char) * l.image_size);
	printf("IMGSIZE:%u\n", (l.image_size));
	read(fd, l.data, l.image_size);
	close(fd);
	glGenTextures(1, &n.texture_id);
	glBindTexture(GL_TEXTURE_2D, n.texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, l.width, l.height, 0, GL_BGR,
			GL_UNSIGNED_BYTE, l.data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	free(l.data);
	return (n.texture_id);
}

GLuint	load_bmp(char *filename)
{
	t_loadbmp		l;
	int				fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putendl("not a correct BMP file !");
		exit(0);
	}
	if (read(fd, l.header, 54) != 54)
	{
		ft_putendl("not a correct BMP file !");
		exit(0);
	}
	if (l.header[0] != 'B' || l.header[1] != 'M')
	{
		ft_putendl("not a correct BMP file !");
		exit(0);
	}
	return (load_bmp2(l, fd));
}
