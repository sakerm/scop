/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:01:22 by lomeress          #+#    #+#             */
/*   Updated: 2015/11/30 13:24:05 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (src[j] != '\0')
		{
			dst[i] = src[j];
			j++;
		}
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
