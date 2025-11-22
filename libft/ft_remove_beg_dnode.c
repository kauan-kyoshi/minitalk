/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_beg_dnode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:56:00 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/30 15:16:14 by kakubo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_remove_beg_dnode(t_dlist *list, void (*free_data)(void *))
{
	t_dnode	*head;

	if (!list || !free_data || !list->head)
		return ;
	head = list->head;
	if (list->head == list->tail)
	{
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
	else
	{
		list->head = list->head->next;
		list->head->prev = NULL;
		list->size--;
	}
	free_data(head->data);
	free(head);
}
