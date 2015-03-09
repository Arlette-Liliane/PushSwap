/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 19:07:59 by aemebiku          #+#    #+#             */
/*   Updated: 2015/03/09 18:37:56 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		my_putchar(char c)
{
	write(1, &c, 1);
}

static void		my_putnbr(int nb)
{
	if (nb < 0)
	{
		my_putchar('-');
		nb = -(nb);
	}
	if (nb >= 10)
		my_putnbr(nb / 10);
	my_putchar((nb % 10) + '0');
}

static void		disp_root(t_list *root)
{
	t_list	*tmp;

	tmp = root->next;
	while (tmp != root)
	{
		my_putnbr(tmp->nb);
		if (tmp->next != root)
			my_putchar(' ');
		tmp = tmp->next;
	}
}

void			disp_list(t_list *root_a, t_list *root_b, int is_last,
							int reverse)
{
	static int	is_first;

	if (is_first++ == 0)
		ft_putstr(("l_a "));
	else
		ft_putstr((root_a->nb_elem == 0) ? ("\nl_a") : ("\nl_a "));
	disp_root(root_a);
	ft_putstr("\n");
	ft_putstr((root_b->nb_elem == 0) ? ("l_b") : ("l_b "));
	disp_root(root_b);
	if (root_b->nb_elem == 0 && is_sort(root_a, reverse) == 1)
		ft_putstr("\n");
	else
		ft_putstr((is_last == 0) ? ("\n\n") : ("\n"));
}

int				ft_doublons(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0 ||
			ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			{
				ft_putstr_error("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
