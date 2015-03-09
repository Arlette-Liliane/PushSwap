/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 18:18:20 by aemebiku          #+#    #+#             */
/*   Updated: 2015/03/09 19:42:00 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_putstr_error(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		write(2, &str[i++], 1);
}

void		my_rotate(t_list **root, int verbose)
{
	(*root)->prec->next = (*root)->next;
	(*root)->next->prec = (*root)->prec;
	(*root)->prec = (*root)->next;
	(*root)->next = (*root)->prec->next;
	(*root)->prec->next = (*root);
	(*root)->next->prec = (*root);
	ft_putstr((verbose == 1) ? ("") : (""));
}

void		my_rotate_end(t_list **root, int verbose)
{
	(*root)->prec->next = (*root)->next;
	(*root)->next->prec = (*root)->prec;
	(*root)->next = (*root)->prec;
	(*root)->prec = (*root)->prec->prec;
	(*root)->prec->next = (*root);
	(*root)->next->prec = (*root);
	ft_putstr((verbose == 1) ? ("") : (""));
}

static int	ft_verif_dec(t_list *root)
{
	t_list	*tmp;
	int		cpt;

	cpt = 0;
	tmp = root->next;
	while (tmp != root)
	{
		if (tmp->prec->nb > tmp->nb)
			cpt++;
		tmp = tmp->next;
	}
	return (cpt);
}

int			ft_isdec(t_list *root)
{
	int		cpt;
	int		verif;
	t_list	*tmp;

	verif = ft_verif_dec(root);
	cpt = 0;
	if ((root->nb_elem - verif) == 1 && root->nb_elem > 2)
	{
		rotate_end(&root, 1);
		tmp = root->next;
		while (tmp != root)
		{
			if (cpt == verif)
			{
				ft_putstr(" sa\n");
				return (1);
			}
			tmp = tmp->next;
			cpt++;
		}
	}
	return (0);
}
