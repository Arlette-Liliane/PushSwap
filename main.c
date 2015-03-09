/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 16:57:53 by aemebiku          #+#    #+#             */
/*   Updated: 2015/03/09 15:45:39 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_min_max(t_list *root, int reverse)
{
	int		min_max;
	t_list	*tmp;
	int		i;
	int		place;

	i = 0;
	tmp = root->next;
	min_max = tmp->nb;
	place = 0;
	while (tmp != root)
	{
		if (reverse == 0 && tmp->nb < min_max)
		{
			min_max = tmp->nb;
			place = i;
		}
		else if (reverse == 1 && tmp->nb > min_max)
		{
			min_max = tmp->nb;
			place = i;
		}
		i = i + 1;
		tmp = tmp->next;
	}
	return (place);
}

static int	put_all_in_a(t_list *root_a, t_list *root_b, int verbose,
						int reverse)
{
	while (root_b->next != root_b)
	{	ft_putstr("lili");
		if ((first_b_in_a(&root_a, &root_b)) == -1)
			return (-1);
		if (verbose == 1)
			ft_putstr("pa");
		else
			ft_putstr((root_b->next != root_b) ? ("pa ") : ("pa"));
		if (verbose == 1)
		{
			disp_list(root_a, root_b, (root_b->next != root_b) ? (0)
						: (1), reverse);
		}
	}
	if (verbose == 0)
		write(1, "\n", 1);
	free_list(root_a);
	free_list(root_b);
	return (0);
}

static int	sort_a(t_list *root_a, t_list *root_b, int verbose,
				int reverse)
{
	int	i;

	while (root_a->next != root_a)
	{
		i = search_min_max(root_a, reverse);
		if (i > (root_a->nb_elem / 2) && (root_a->nb_elem) != 1)
			while (i++ < root_a->nb_elem)
			{
				ft_myfct_end(root_a, root_b, verbose, reverse);
			}
		else
		{
			while (i-- > 0)
			{
				ft_myfct(root_a, root_b, verbose, reverse);
			}
		}
		if (root_b->nb_elem == 0 && is_sort(root_a, reverse) == 1)
			return (0);
		if ((first_a_in_b(&root_a, &root_b, verbose, reverse)) == -1)
			return (-1);
		if (root_b->nb_elem == 0 && is_sort(root_a, reverse) == 1)
			return (0);
	}
	return (0);
}

static int	get_arg(char **argv, int *verbose, t_list **root_a)
{
	t_list	*tmp;
	int		reverse;
	int		i;

	i = 1;
	reverse = 0;
	tmp = *root_a;
	while (argv[i])
	{
		if (is_good_param(argv[i], verbose, &reverse) == -1)
			return (-1);
		if (argv[i][1] != 'v' && argv[i][1] != 'r')
			if ((push_back(&tmp, ft_atoi(argv[i]))) == -1)
				return (-1);
		i = i + 1;
	}
	return (reverse);
}

int			main(int argc, char **argv)
{
	t_list	*root_a;
	t_list	*root_b;
	int		verbose;
	int		reverse;

	verbose = 0;
	if (usage(argc, argv) == 1 || ft_doublons(argc, argv))
		return (0);
	if ((init_roots(&root_a, &root_b)) == -1)
		return (-1);
	if ((reverse = get_arg(argv, &verbose, &root_a)) == -1)
		return (-1);
	(verbose == 1) ? (disp_list(root_a, root_b, 0, reverse)) : (0);
	if (is_sort(root_a, reverse) == 1)
		return ((verbose == 0) ? (write(1, "\n", 1) - 1) : (0));
	if (ft_caspar(root_a) || ft_isdec(root_a))
		return (0);
	if ((sort_a(root_a, root_b, verbose, reverse)) == -1)
		return (-1);
	put_all_in_a(root_a, root_b, verbose, reverse);
	return (0);
}
