/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:44:52 by lomeress          #+#    #+#             */
/*   Updated: 2016/01/03 12:49:32 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = -1;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i <= size)
		str[i] = 0;
	return (str);
}
