/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:49:26 by lomeress          #+#    #+#             */
/*   Updated: 2016/01/29 15:22:21 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstt;
	unsigned char	*srct;

	dstt = (unsigned char*)dst;
	srct = (unsigned char*)src;
	while (n--)
	{
		*dstt = *srct++;
		dstt++;
	}
	return (dst);
}
