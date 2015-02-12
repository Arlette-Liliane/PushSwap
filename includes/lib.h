/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 14:20:05 by aemebiku          #+#    #+#             */
/*   Updated: 2015/02/05 13:51:27 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putchar_error(char c);
void	ft_error(char *s);
void	ft_putnbr_base_fd(long int n, int base, int fd);
void	ft_putnbr_base(long int n, int base);
void	ft_putnbr(long int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		ft_isdigit(char **av, int ac);
int		ft_doublons(int ac,char **av);
#endif
