/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:28:48 by lomeress          #+#    #+#             */
/*   Updated: 2016/01/29 15:05:22 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len;

	len = ft_strlen(s1);
	i = len - 1;
	while (++i < len + n && *s2 != '\0')
		s1[i] = *s2++;
	s1[i] = '\0';
	return (s1);
}
