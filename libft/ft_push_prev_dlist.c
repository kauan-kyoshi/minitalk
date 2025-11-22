/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_prev_dlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:53:26 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/30 15:16:11 by kakubo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_push_prev_dlist(t_dlist *list, t_dnode *to, void *data)
{
	t_dnode	*node;

	if (!list || !to)
		return ;
	if (to == list->head)
		ft_push_beg_dlist(list, data);
	else
	{
		node = ft_create_dnode(data);
		if (!node)
			return ;
		node->next = to;
		node->prev = to->prev;
		to->prev->next = node;
		to->prev = node;
		list->size++;
	}
}
