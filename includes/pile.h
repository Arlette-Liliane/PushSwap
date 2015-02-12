/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 14:20:05 by aemebiku          #+#    #+#             */
/*   Updated: 2015/02/09 14:23:03 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
# define PILE_H
#include "pile_struct.h"
#include "lib.h"

void	Init(dblist *l);
void	PushBack(dblist *l, int val);
void	PushFront(dblist *l, int val);
int 	PopBack(dblist *l);
int		PopFront(dblist *l);
void Swap(dblist *l);
int		Count_pile(dblist l);
void	rotate_list(dblist *l);
void	reverse_list(dblist *l);
void	View(dblist l);
int		ft_min(dblist *l);
int		is_sort(dblist *l);
Pile	ft_PushList(Pile a);
void		push_swap(dblist *l_a, dblist *l_b);
void	Clear(dblist *l);
Pile	ft_Fusion(Pile la, Pile lb);
dblist *Pop(dblist *l, int values);

#endif
