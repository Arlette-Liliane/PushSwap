/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:01:31 by aemebiku          #+#    #+#             */
/*   Updated: 2015/03/06 17:26:40 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		first_b_in_a(t_list **root_a, t_list **root_b)
{
	t_list	*tmp;

	if ((push_front(root_a, (*root_b)->next->nb)) == -1)
		return (-1);
	tmp = (*root_b)->next;
	(*root_b)->next = (*root_b)->next->next;
	(*root_b)->nb_elem = (*root_b)->nb_elem - 1;
	free(tmp);
	return (0);
}

int		first_a_in_b(t_list **root_a, t_list **root_b, int verbose,
					int reverse)
{
	t_list	*tmp;

	if ((push_front(root_b, (*root_a)->next->nb)) == -1)
		return (-1);
	tmp = (*root_a)->next;
	(*root_a)->next = (*root_a)->next->next;
	(*root_a)->nb_elem = (*root_a)->nb_elem - 1;
	free(tmp);
	ft_putstr((verbose == 1) ? ("pb") : ("pb "));
	(verbose == 1) ? (disp_list(*root_a, *root_b, 0, reverse)) : (0);
	return (0);
}

void	rotate(t_list **root, int verbose)
{
	(*root)->prec->next = (*root)->next;
	(*root)->next->prec = (*root)->prec;
	(*root)->prec = (*root)->next;
	(*root)->next = (*root)->prec->next;
	(*root)->prec->next = (*root);
	(*root)->next->prec = (*root);
	ft_putstr((verbose == 1) ? ("ra") : ("ra "));
}

void	rotate_end(t_list **root, int verbose)
{
	(*root)->prec->next = (*root)->next;
	(*root)->next->prec = (*root)->prec;
	(*root)->next = (*root)->prec;
	(*root)->prec = (*root)->prec->prec;
	(*root)->prec->next = (*root);
	(*root)->next->prec = (*root);
	ft_putstr((verbose == 1) ? ("rra") : ("rra "));
}

int		is_sort(t_list *root, int reverse)
{
	t_list	*tmp;

	tmp = root->next->next;
	while (tmp != root)
	{
		if (reverse == 0 && tmp->prec->nb > tmp->nb)
			return (-1);
		else if (reverse == 1 && tmp->prec->nb < tmp->nb)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}
