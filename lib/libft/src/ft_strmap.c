/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:36:42 by lomeress          #+#    #+#             */
/*   Updated: 2016/01/03 12:51:15 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	i = -1;
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i] != '\0')
		new[i] = f(s[i]);
	new[i] = '\0';
	return (new);
}
