/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 14:13:37 by aemebiku          #+#    #+#             */
/*   Updated: 2015/02/09 15:04:12 by aemebiku         ###   ########.fr       */
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

dblist  *Pop(dblist *l, int values)
{
   Pile *tmp;

   tmp  = l->first;
   if(!tmp)
	return NULL;
	while (tmp)
	{
		View(*l);
		if (values == tmp->val)
	   {
		   
		   	if(tmp->next == NULL)
		   	{
		   		l->last = tmp->prev;
		   		l->last->prev = NULL;
		   	}
		   	else if (tmp->prev == NULL)
	   		{
	   			l->first = tmp->next;
	   			l->first->prev =  NULL;
	   		}
	   		else
	   		{
	   			tmp->next->prev = tmp->prev;
	   			tmp->prev->next = tmp->next;
	   		}
				
			 free(tmp);
		
			 
	   }
	   else{
	   	   tmp = tmp->next;
	   }
	
	   
	}	

	return l; 
}


void Swap(dblist *l)
{
	Pile *tmp;
	Pile *tmp2;

  ft_putstr("sa");
	if (l->first)
	{

		tmp = l->first->next;
		l->first->next = NULL;
		while(tmp->next)
		{
			tmp2 = tmp->next;
			tmp->next = l->first;
			l->first = tmp;
			tmp = tmp2;
		}
		
	}
return;
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

void ViewPile(Pile *pelem)
{

   while(pelem != NULL)
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

	tmp = l->first;
	if (!tmp)
		return (0);
	flag = 0;
	prev = tmp->val;
	while (tmp)
	{
		if (!flag)
			tmp = l->first;
		flag = 1;
		if (tmp->val < prev)
			return (0);
		prev = tmp->val;

		tmp = tmp->next;
	}
	return 1;
}


void	lst_shift(dblist *list)
{
	dblist	*this;

	ft_putstr("ra");
	this = (dblist *)list;
	if (!this->first)
		return ;
	//Swap(list);
	this->first = this->first->next;
	
	//View(*list);
}

void	empty_list(dblist *l_a, dblist *l_b)
{
	Pile *tmp1;


	tmp1 = l_b->first;
	while (tmp1)
	{
		ft_putstr(" pa");
		PushBack(l_a, tmp1->val);
		PopFront(l_b);
		tmp1 = tmp1->next;
	}
	ft_putstr("\n");
}

void	lst_pop(dblist *list)
{
	dblist	*this;
	Pile	*tmp;

	this = (dblist *)list;
	if (!this->first)
		return ;
	if (this->first == this->first->next)
	{
		free(this->first);
		this->first = NULL;
	}
	else
	{
		tmp = this->first;
		this->last->prev = this->first->next;
		this->first->next = this->last->prev;
		this->first = this->first->next;
		free(tmp);
	}
}

void		push_swap(dblist *l_a, dblist *l_b)
{
	int		flag;
	int		min;

	Pile	*tmp;

	min = ft_min(l_a);
	flag = 0;
	while (l_a->first && !is_sort(l_a))
	{
		if (flag)
			ft_putstr(" ");
		flag = 1;
		tmp = l_a->first;
		if (tmp->val == min)
		{
			//View(*l_a);
			ft_putstr("pb");
			PushBack(l_b, tmp->val);

			//PopFront(l_a);
			lst_pop(l_a);

		
			
			min = ft_min(l_a);
		}
		else{
			lst_shift(l_a);
		}
			View(*l_a);
	}
	/*View(*l_b);
		View(*l_a);*/

	empty_list(l_a, l_b);
	//View(*l_a);
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
