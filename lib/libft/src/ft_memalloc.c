/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:36:25 by lomeress          #+#    #+#             */
/*   Updated: 2015/11/30 15:38:13 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*mem;

	i = 0;
	if (!(mem = (unsigned char*)malloc(sizeof(mem) * size)))
		return (NULL);
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void*)mem);
}
