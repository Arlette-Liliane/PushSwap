/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 13:30:30 by aemebiku          #+#    #+#             */
/*   Updated: 2015/03/09 17:58:27 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_myfct_end(t_list *root_a, t_list *root_b, int verbose,
							int reverse)
{
	rotate_end(&root_a, verbose);
	(verbose == 1) ? disp_list(root_a, root_b, 0, reverse) : 0;
}

void			ft_myfct(t_list *root_a, t_list *root_b, int verbose,
						int reverse)
{
	rotate(&root_a, verbose);
	(verbose == 1) ? disp_list(root_a, root_b, 0, reverse) : 0;
}

static int		ft_verif(t_list *root)
{
	t_list	*tmp;
	int		cpt;

	cpt = 0;
	tmp = root->next->next;
	while (tmp != root)
	{
		if (tmp->prec->nb > tmp->nb)
			return (cpt);
		tmp = tmp->next;
		cpt++;
	}
	return (cpt);
}

int				ft_caspar(t_list *root)
{
	int		cpt;
	int		verif;
	t_list	*tmp;

	verif = ft_verif(root);
	cpt = 0;
	if ((root->nb_elem - verif) == 2 && root->nb_elem > 2)
	{
		tmp = root->next->next;
		while (tmp != root)
		{
			if (cpt == verif)
			{
				my_rotate(&root, 1);
				ft_putstr("sa\n");
				return (1);
			}
			tmp = tmp->next;
			cpt++;
		}
	}
	return (0);
}
