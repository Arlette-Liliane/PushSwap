/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 14:13:37 by aemebiku          #+#    #+#             */
/*   Updated: 2015/02/05 15:50:32 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pile.h"

void Init(dblist *l)
{
   l->first = NULL;
   l->last = NULL;
}

void PushBack(dblist *l, int val)
{
  Pile *nouv = malloc(sizeof(Pile));
   if(!nouv) 
	exit(EXIT_FAILURE);
   nouv->val = val;
   nouv->prev = l->last;
   nouv->next = NULL;
   if(l->last) 
	l->last->next = nouv;
   else 
	l->first = nouv;
   l->last = nouv;        
}

void PushFront(dblist *l, int val)
{
   Pile *nouv ;
   
   nouv = malloc(sizeof(Pile));
   if(!nouv) 
	exit(EXIT_FAILURE);
   nouv->val = val;
   nouv->next = l->first;
   nouv->prev = NULL;      
   if(l->first) 
	l->first->prev = nouv;
   else 
	l->last = nouv;
   l->first = nouv;
}

int PopBack(dblist *l)
{
   int val;
   Pile *tmp;
   
   tmp = l->last;
   if(!tmp) 
	return -1;
   val = tmp->val;
   l->last = tmp->prev;
   if(l->last) 
	l->last->next = NULL;
   else 
	l->first = NULL;
   free(tmp);
   return val;
}
/******************************************************************************/

int PopFront(dblist *l)
{
   int val;
   Pile *tmp;
   
   tmp  = l->first;
   if(!tmp) 
	return -1;
   val = tmp->val;
   l->first = tmp->next;
   if(l->first)
	l->first->prev = NULL;
   else 
	l->last = NULL;
   free(tmp);
   return val;
}

void Swap(dblist *l)
{
	Pile *tmp;
	Pile *tmp2;
	if (l->first && l->first->next)
	{
		tmp = l->first;
		tmp2 = l->first->next;
		tmp->next = tmp2->next;
		tmp2->next = tmp;
		l->first = tmp2;
	}
	
}

int Count_pile(dblist l)
{
	int	count;
	Pile *ppile;
	
	count = 0;
	ppile = l.first;
	while(ppile)
	{
     count++;
     ppile = ppile->next;
	}
	return count;
}

//vers le haut, le premier élément devient le dernier
void rotate_list(dblist *l)
{
	int	val;

	ft_putstr("ra");	
	val = PopBack(l);
	PushFront(l, val);
	
	
	
}

//vers le bas, le dernier élément devient le premier
void reverse_list(dblist *l)
{
	int	val;
	
	ft_putstr("rra");
	val = PopFront(l);
	PushBack(l, val);
	
}



void View(dblist l)
{
   Pile *pelem = l.first;

   while(pelem)
   {
     ft_putnbr(pelem->val);
     ft_putchar('\n');
     pelem = pelem->next;
   }
   ft_putstr("--------------");
}

int	ft_min(dblist *l)
{
	Pile	*tmp;
	int		min;

	tmp = l->first;
	if (!tmp)
		return -1;
	min = l->first->val;
	while (tmp)
	{
		rotate_list(l);
		if (min > tmp->val)
		{

			min = tmp->val;
		}
		tmp = tmp->next;
	}
	return min;
}

int		is_sort(dblist *l)
{
	int	flag;
	int	prev;
	Pile *tmp;

	tmp = l->last;
	if (!tmp)
		return (0);
	flag = 0;
	prev = tmp->val;
	while (!tmp)
	{
		if (!flag)
			tmp = l->last;
		flag = 1;
		if (tmp->val < prev)
			return (0);
		prev = tmp->val;
		tmp = tmp->next;
	}
	return 0;
}

void	ft_PushList(dblist *a, dblist *b)
{
	int	val;
	int tail;

	tail = Count_pile(*a) / 2;
	val = 0;
	while (tail > 0 && b->first)
	{
		ft_putstr("pb");
		val = PopFront(a);
		PushBack(b, val);
		tail--;

	}
	View(*a);
	View(*b);
}

void	ft_Fusion(dblist *a, dblist *b)
{
	Pile *tmp;
	Pile *tmp2;

	tmp = a->first;
	tmp2 = b->first;
	if (!tmp)
		exit(EXIT_FAILURE);
	else if (!tmp2)
		exit(EXIT_FAILURE);
	else if ((tmp->val) <= (tmp2->val))
	{
		ft_putstr("pa");
		PushFront(a, tmp->val);
		ft_Fusion(tmp->next, b);
		exit(EXIT_FAILURE);

	}
	else 
	{
		ft_putstr("pa");
		PushFront(a, tmp2->val);
		ft_Fusion(a, tmp2->next);
		exit(EXIT_FAILURE);
	}
}


void	ft_PushSwap(dblist *a, dblist *b)
{
	//int	flag;https://github.com/gabtoubl/portfolio/blob/master/Algorithmie/push_swap/algo.c
	//int	min;
	Pile	*tmp;
	//Pile 	*tmp1;
	//int	val;http://zanotti.univ-tln.fr/enseignement/I51/solutions/tri-fusion-liste.c

	//val = 0;
	tmp = a->first;
	//min = ft_min(a);
	if (tmp)
	{
		if (tmp->next)
		{
			ft_PushList(a, b);
			ft_PushSwap(a, b);
			//ft_Fusion(a->first, b->first);
		}
	}
	View(*a);
}

void	Clear(dblist *l)
{
	Pile	*tmp;
	Pile	*pelem; 

	pelem = l->first;
	while(pelem)
	{
		tmp = pelem;
		pelem = pelem->next;
		free(tmp);
	}
	l->first = NULL;
	l->last = NULL;
}

