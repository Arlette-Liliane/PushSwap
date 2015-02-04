#include <stdlib.h>
#include <stdio.h>

#include "pile.h"

int main(int ac, char ** av)
{
        dblist MaListe;
        int it;
 
        it = 1;
        
        if (ac > 2)
        {
			while (it < ac)
			{
				PushBack(&MaListe,ft_atoi(av[it]));
				it++;
			}
			View(MaListe);
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
		}
		else
			ft_error("ERROR: Please enter the numbers");
			
        return 0;    
 }
