/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:01:07 by aemebiku          #+#    #+#             */
/*   Updated: 2015/03/09 18:27:27 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct					s_list
{
	int							nb;
	int							nb_elem;
	struct s_list				*prec;
	struct s_list				*next;
}								t_list;

int								push_back(t_list **list, int nb);
int								push_front(t_list **list, int nb);
long long int					ft_atoi(char *str);
int								ft_strcmp(const char *s1, const char *s2);
int								usage(int argc, char **argv);
int								ft_doublons(int ac, char **av);
void							swap_two_first(t_list **root, char c);
void							my_putstr(char *str);
int								first_b_in_a(t_list **root_a, t_list **root_b);
int								first_a_in_b(t_list **root_a, t_list **root_b,
								int verbose, int reverse);
void							swap_two(t_list **root_a, t_list **root_b);
void							rotate(t_list **root, int verbose);
void							rotate_end(t_list **root, int verbose);
int								init_roots(t_list **root_a, t_list **root_b);
void							disp_list(t_list *root_a, t_list *root_b,
								int is_last, int reverse);
void							free_list(t_list *root);
int								is_sort(t_list *root, int reverse);
int								is_good_param(char *str, int *verbose,
								int *reverse);
void							ft_putstr(char *str);
void							ft_putstr_error(char *str);
void							ft_myfct_end(t_list *root_a, t_list *root_b,
								int verbose, int reverse);
void							ft_myfct(t_list *root_a, t_list *root_b,
								int verbose, int reverse);
void							my_rotate(t_list **root, int verbose);
void							my_rotate_end(t_list **root, int verbose);
int								ft_isdec(t_list *root);
int								ft_caspar(t_list *root);
#endif
