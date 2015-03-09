/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_linked.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:00:36 by aemebiku          #+#    #+#             */
/*   Updated: 2015/03/06 16:23:35 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list		*create_list(int nb)
{
	t_list	*new;

	new = NULL;
	new = (t_list*)malloc(sizeof(*new));
	if (new)
	{
		new->nb = nb;
		new->prec = NULL;
		new->next = NULL;
	}
	if (!(new))
		ft_putstr_error("error: Could not alloc\n");
	return (new);
}

int					push_back(t_list **root, int nb)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *root;
	new = create_list(nb);
	if (new)
	{
		new->prec = tmp->prec;
		new->next = tmp;
		tmp->prec->next = new;
		tmp->prec = new;
		(*root)->nb_elem = (*root)->nb_elem + 1;
		return (0);
	}
	return (-1);
}

int					push_front(t_list **root, int nb)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *root;
	new = create_list(nb);
	if (new)
	{
		new->prec = tmp;
		new->next = tmp->next;
		tmp->next->prec = new;
		tmp->next = new;
		(*root)->nb_elem = (*root)->nb_elem + 1;
		return (0);
	}
	return (-1);
}

int					init_roots(t_list **root_a, t_list **root_b)
{
	if ((*root_a = (t_list*)malloc(sizeof(**root_a))) == NULL)
	{
		ft_putstr_error("error: Could not alloc\n");
		return (-1);
	}
	(*root_a)->nb_elem = 0;
	(*root_a)->next = (*root_a);
	(*root_a)->prec = (*root_a);
	if ((*root_b = (t_list*)malloc(sizeof(**root_b))) == NULL)
	{
		ft_putstr_error("error: Could not alloc\n");
		return (-1);
	}
	(*root_b)->nb_elem = 0;
	(*root_b)->next = (*root_b);
	(*root_b)->prec = (*root_b);
	return (1);
}

void				free_list(t_list *root)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = root->next;
	while (tmp != root)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
}
