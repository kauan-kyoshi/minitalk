/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_dnode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:12:24 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/30 15:16:16 by kakubo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_remove_dnode(t_dlist *list, t_dnode *node, void (*free_data)(void *))
{
	if (!list || !node || !free_data)
		return ;
	if (node == list->head)
		ft_remove_beg_dnode(list, free_data);
	else if (node == list->tail)
		ft_remove_lst_dnode(list, free_data);
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free_data(node->data);
		free(node);
		list->size--;
	}
}
