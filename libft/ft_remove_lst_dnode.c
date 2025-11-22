/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_lst_dnode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:57:09 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/30 15:16:19 by kakubo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_remove_lst_dnode(t_dlist *list, void (*free_data)(void *))
{
	t_dnode	*tail;

	if (!list || !free_data || !list->tail)
		return ;
	tail = list->tail;
	if (list->head == list->tail)
	{
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
	else
	{
		list->tail = list->tail->prev;
		list->tail->next = NULL;
		list->size--;
	}
	free_data(tail->data);
	free(tail);
}
