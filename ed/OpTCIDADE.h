#include "TCIDADE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ImprimeLista(TLista *lst, char *cabec)
{	int c;

	printf("\n\n%s\n", cabec);
	c = 0;
	while (c <= lst->final)
	{	printf("%3d: %-21s %10d %6.1f\n", c + 1, lst->lista[c].nome,
										 lst->lista[c].pop,
										 lst->lista[c].area);
		c = c + 1;
	}
}

void InicializaLista(TLista *lst)
{	lst->final = -1;
	lst->totPop = 0;
}

void InsereLista(TLista *lst, TCidade pDados)
{	lst->final++;

	strcpy(lst->lista[lst->final].nome, pDados.nome);
	lst->lista[lst->final].pop = pDados.pop;
	lst->lista[lst->final].area = pDados.area;

	lst->totPop = lst->totPop + lst->lista[lst->final].pop;
}

void ExcluiLista(TLista *lst, TCidade *p)
{	int c = p - lst->lista;

	lst->totPop = lst->totPop - lst->lista[c].pop;

	while (c < lst->final)
	{	lst->lista[c] = lst->lista[c + 1];
		c = c + 1;
	}
	lst->final = lst->final - 1;
}

TCidade *PesquisaListaNome(TLista *lst, TCidade p)
{	int c = 0;

	while (c <= lst->final && strcmp(p.nome, lst->lista[c].nome) != 0)
		c = c + 1;

	if (c < lst->final)
		return &(lst->lista[c]);
	else
		return NULL;
}
