/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_next_dlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:40:50 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/30 15:16:08 by kakubo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_push_next_dlist(t_dlist *list, t_dnode *to, void *data)
{
	t_dnode	*node;

	if (!list || !to)
		return ;
	if (to == list->tail)
		ft_push_lst_dlist(list, data);
	else
	{
		node = ft_create_dnode(data);
		if (!node)
			return ;
		node->prev = to;
		node->next = to->next;
		to->next->prev = node;
		to->next = node;
		list->size++;
	}
}
