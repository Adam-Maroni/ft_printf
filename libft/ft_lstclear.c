/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:50:52 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/14 15:36:06 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;
	t_list *previous;

	previous = (*lst)->next;
	while (previous)
	{
		current = previous->next;
		ft_lstdelone(previous, (*del));
		previous = current;
	}
	ft_lstdelone(*lst, (*del));
	(*lst) = NULL;
}
