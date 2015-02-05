/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:07:25 by aemebiku          #+#    #+#             */
/*   Updated: 2015/02/05 15:22:47 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
	ft_putchar('\n');
}

int	ft_isdigit(char **av, int ac)
{
	int		i;
	char	*s;
	int		isint;
	
	s = NULL;
	i = 1;
	while (i < ac)
	{
		isint = -1;
		s = av[i];
		if (*s == '-')
		{
			s++;
			while (*s)
			{
				if ('0' <= *s && *s <= '9')
					isint = 1;
				else
					return (0);
				s++;
			}
			if (isint == -1)
				return 0;
		}
		else {
			while (*s)
            {
                if ('0' <= *s && *s <= '9')
					isint = 1;
                else
					return (0);
                s++;
			}
		}
		i++;
	}
	return isint;
}


void	ft_putchar_error(char c)
{
	write(2, &c, 1);
}

void	ft_error(char *s)
{
	while(*s)
	{
		ft_putchar_error(*s);
		s++;
	}
	ft_putchar('\n');
	exit(EXIT_FAILURE);
}

void	ft_putnbr_base_fd(long int n, int base, int fd)
{
	long int	div;
	char		temp;
	
	if (base != 10)
		n = (unsigned long int)n;
	div = 1;
	if (n < 0)
		write(fd, "-", 1);
	if (n < 0)
		n = -n;
	while (n / div >= base)
		div *= base;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 39;
			write(fd, &temp, 1);
		}
		else
			write(fd, &temp, 1);
		n %= div;
		div /= base;
	}
}
void	ft_putnbr_base(long int n, int base)
{
	ft_putnbr_base_fd(n, base, 1);
}

void	ft_putnbr(long int n)
{
	ft_putnbr_base_fd(n, 10, 1);
}


int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char *)s2);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	signe;
	
	i = 0;
	n = 0;
	signe = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
	|| str[i] == '\f' || str[i] == '\n')
		i++;
	signe = (str[i] == '-') ? -signe : signe;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] && str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * signe);
}

//verifier que c'est un int et qu'il ya pas de doublon

int	ft_doublons(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	while(i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
			i++;
	}
	return 0;
}
