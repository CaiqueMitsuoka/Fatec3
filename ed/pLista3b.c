/*
	Implementa uma lista linear de cidades por CONTIGUIDADE
	com descritor estruturado. Usa subrotinas para as operacoes basicas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_TAM 200
#include "TCIDADE.h"
#include "OpTCIDADE.h"


int main()
{	TCidade vDadosInfo, *x;
	TLista lst;

	InicializaLista(&lst);

	while (1)
	{	printf("Informe o nome da cidade ou 'FIM' para encerrar:\n");
		scanf("%s", vDadosInfo.nome);

		if (strcmp(vDadosInfo.nome, "FIM") == 0)
			break;

		printf("Informe a populacao:\n");
		scanf("%d", &vDadosInfo.pop);

		printf("Informe a area:\n");
		scanf("%f", &vDadosInfo.area);

		InsereLista(&lst, vDadosInfo);
	}

	ImprimeLista(&lst, (char*)"Os valores informados foram:");

	while(1){
		printf("Informe o nome da cidade desejada:\n");
		scanf("%s", vDadosInfo.nome);
		if(!strcmp(vDadosInfo.nome,"FIM")){
			break;
		}

		x = PesquisaListaNome(&lst, vDadosInfo);

		if (x == NULL)
			printf("Cidade nao encontrada na lista\n");
		else
			/* Excluindo o elemento da lista */
			ExcluiLista(&lst, x);
	}
		ImprimeLista(&lst, (char*)"Novo conteudo da lista:");

	return 0;
}
