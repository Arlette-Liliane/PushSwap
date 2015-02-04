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
