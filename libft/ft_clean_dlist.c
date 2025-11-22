/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_dlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakubo-l <kakubo-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:58:08 by mhidani           #+#    #+#             */
/*   Updated: 2025/10/30 15:15:42 by kakubo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	ft_clean_dlist(t_dlist **list, void (*free_data)(void *))
{
	t_dnode	*tmp;
	t_dnode	*pivot;

	if (!list || !free_data)
		return ;
	pivot = (*list)->head;
	while (pivot != NULL)
	{
		tmp = pivot;
		pivot = pivot->next;
		free_data(tmp->data);
		free(tmp);
	}
	free(*list);
	*list = NULL;
}
