/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 14:13:37 by aemebiku          #+#    #+#             */
/*   Updated: 2015/02/03 14:13:38 by aemebiku         ###   ########.fr       */
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
	
	val = PopBack(l);
	PushFront(l, val);
	
	
	
}

//vers le bas, le dernier élément devient le premier
void reverse_list(dblist *l)
{
	int	val;
	
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
}



