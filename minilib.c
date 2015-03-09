/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:30:06 by aemebiku          #+#    #+#             */
/*   Updated: 2015/03/09 18:57:12 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
}

long long int			ft_atoi(char *str)
{
	int				i;
	int				negativ;
	long long int	number;

	i = 0;
	negativ = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
		negativ = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += ((int)str[i] - 48);
		i++;
	}
	if (negativ == 1)
		return (-number);
	else
		return (number);
}

int						ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char *)s2);
}

int						is_good_param(char *str, int *verbose, int *reverse)
{
	int	i;

	i = 0;
	if (str && str[0] == '-' && str[1] == 'v' && str[2] == 0)
	{
		*verbose = 1;
		return (0);
	}
	if (str && str[0] == '-' && str[1] == 'r' && str[2] == 0)
	{
		*reverse = 1;
		return (0);
	}
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
		{
			ft_putstr_error("Error");
			ft_putstr_error("\n");
			return (-1);
		}
		i = i + 1;
	}
	return (0);
}

int						usage(int argc, char **argv)
{
	int	i;
	int	is_help;

	i = 1;
	is_help = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--help") == 0)
			is_help = 1;
		i = i + 1;
	}
	if (argc == 1)
		is_help = 1;
	if (is_help == 0)
		return (0);
	ft_putstr("usage: ./push_swap [OPTION]... [NB1 NB2...]\n\n");
	ft_putstr("\t-r      reverse sort\n");
	ft_putstr("\t-v      print state of list each step\n");
	ft_putstr("\t--help  print this message\n");
	return (1);
}
