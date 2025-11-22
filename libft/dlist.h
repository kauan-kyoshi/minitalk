/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:03:00 by mhidani           #+#    #+#             */
/*   Updated: 2025/09/28 15:40:15 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include <stdlib.h>

typedef struct s_dnode
{
	void			*data;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}	t_dnode;

typedef struct s_dlist
{
	struct s_dnode	*head;
	struct s_dnode	*tail;
	unsigned long	size;
}	t_dlist;

t_dnode	*ft_create_dnode(void *data);
t_dlist	*ft_create_dlist(t_dnode *node);
void	ft_push_lst_dlist(t_dlist *list, void *data);
void	ft_push_beg_dlist(t_dlist *list, void *data);
void	ft_push_next_dlist(t_dlist *list, t_dnode *to, void *data);
void	ft_push_prev_dlist(t_dlist *list, t_dnode *to, void *data);
void	ft_remove_beg_dnode(t_dlist *list, void (*f)(void *));
void	ft_remove_lst_dnode(t_dlist *list, void (*f)(void *));
void	ft_remove_dnode(t_dlist *list, t_dnode *node, void (*f)(void *));
void	ft_clean_dlist(t_dlist **list, void (*f)(void *));
size_t	ft_indexof_dlist(t_dlist *list, t_dnode *target);

#endif
