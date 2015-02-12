//-------------------------------------------------------------------
// ALGORITHME: TRI FUSION AVEC LISTE CHAINEE
//
// ENTREE: fichier de nombres entiers
// SORTIE: les nombres entiers tries dans l'ordre croissant par fusion
//
// NB: utiliser le programme gentab pour creer la liste
//-------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long telem;

typedef struct tcell
{
	telem elem;
	struct tcell *suiv;
} TCELL;

typedef TCELL *TLISTE;

TLISTE liste;

void Afficher(TLISTE liste)
{
	while (liste != NULL)
    {
		printf("%llu ",liste->elem);
		liste = liste->suiv;
    }
	printf("\n");
}
void Empiler(TLISTE *liste, telem x)
{
	TLISTE aux = NULL;

	aux = (TLISTE) malloc(sizeof(TCELL));
	aux->elem = x;
	aux->suiv = (*liste);
	*liste = aux;
}

TLISTE Lire(FILE * fichier)
{
	telem x;
	TLISTE liste;

	liste = NULL;
	while (fscanf(fichier,"%llu",&x) != EOF)
		Empiler(&liste,x);
	return liste;
}


// coupe la liste en 2 listes en prenant un terme sur deux
TLISTE Separer(TLISTE liste)
{TLISTE aux;

	if (liste == NULL)
		return(NULL);
	else if (liste->suiv == NULL)
		return(NULL);
	else
	{
		aux = liste->suiv;
		liste->suiv = aux->suiv;
		aux->suiv=Separer(aux->suiv);
		Afficher(liste);
		return(aux);
	}
}

TLISTE Fusion(TLISTE lg,TLISTE ld)
{
/*	printf("----lg-----\n");
	Afficher(lg);
printf("----ld-----\n");
	Afficher(ld);*/

	if (lg == NULL)
		return(ld);
	else if (ld == NULL)
		return(lg);
	else if ((lg->elem) <= (ld->elem))
    {
		lg->suiv = Fusion(lg->suiv,ld);
		return(lg);
    }
	else
    {
		ld->suiv = Fusion(lg,ld->suiv);
		return(ld);
    }
}



void Trier(TLISTE* liste)
{TLISTE aux;

	if (*liste != NULL)
		if ((*liste)->suiv != NULL)
		{
			aux=Separer(*liste);
			Trier(liste);
			Trier(&aux);
			*liste=Fusion(*liste,aux);
		}
}

int main(int argc, char* argv[])
{
	FILE *source;

	if (argc < 2)
		source = stdin;
	else
		source = fopen(argv[1],"r");
	if (source == NULL)
    {
		printf("Fichier introuvable. Voir gentab.c\n");
		printf("Syntaxe: %s [fichier]\n",argv[0]);
		return 1;
    }
	liste = Lire(source);
	fclose(source);
	Afficher(liste);
	Trier(&liste);
	Afficher(liste);
	return 0;
}
