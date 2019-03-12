/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:11:54 by lomeress          #+#    #+#             */
/*   Updated: 2016/01/29 14:41:14 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s, int size)
{
	int		i;
	char	*srev;

	i = 0;
	if (!(srev = ft_strnew(size)))
		return (NULL);
	while (--size >= 0)
		srev[i++] = s[size];
	srev[i] = '\0';
	return (srev);
}
