/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:31:36 by lomeress          #+#    #+#             */
/*   Updated: 2016/01/29 15:24:03 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*st;

	st = (unsigned char*)s;
	while (n--)
	{
		if (*st == (unsigned char)c)
			return (st);
		st++;
	}
	return (NULL);
}
