/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:30:44 by lomeress          #+#    #+#             */
/*   Updated: 2015/11/28 10:15:27 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*current;

	current = *alst;
	next = current->next;
	while (next != NULL)
	{
		del(current->content, current->content_size);
		next = current->next;
		free(current);
		current = next;
	}
	*alst = NULL;
}
