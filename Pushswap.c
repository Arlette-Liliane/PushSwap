/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:16:24 by aemebiku          #+#    #+#             */
/*   Updated: 2015/02/05 15:23:37 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

#include "pile.h"

int main(int ac, char ** av)
{
        dblist MaListea;
        dblist MaListeb;
        int it;
 
        it = 1;
        Init(&MaListea);
        Init(&MaListeb);
        
        if (ac > 2 && ft_isdigit(av, ac) == 1 && ft_doublons(ac, av) == 0)
        {
			while (it < ac)
			{

				PushBack(&MaListea,ft_atoi(av[it]));
				it++;
			}
			ft_PushSwap(&MaListea, &MaListeb);
			Clear(&MaListea);
			Clear(&MaListeb);

			/*View(MaListe);
			ft_putstr("--------------");
			rotate_list(&MaListe);
			View(MaListe);
			 ft_putstr("--------------");
			 reverse_list(&MaListe);
			View(MaListe);
			 ft_putstr("--------------");
			 Swap(&MaListe);
			View(MaListe);
			 ft_putstr("--------------");
         printf("min : %d\n", ft_min(&MaListe));*/
		}
		else
		  ft_error("Error");
		printf(" doublons : %d\n", ft_isdigit(av, ac));			
        return 0;    
 }
