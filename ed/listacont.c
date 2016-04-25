#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_TAM 200

struct regCid
{
	char nome[21];
	int pop;
	float area;
};
typedef struct regCid TCidade;

int imprimir(TCidade *vet, int *lim){
	int a=0;
	while(a < *lim){
		printf("%-25s %10d %6.1f\n", vet[a].nome, vet[a].pop, vet[a].area);
		a++;
	}
	return 0;
}

int excluir(TCidade *vet, char *nome, int *final){
	int c = 0;
	while(c <= *final && strcmp(nome, vet[c].nome) != 0)
		c++;

	if(c > *final)
		return 1;
	else
	{
		while(c < *final)
		{
			vet[c] = vet[c+1];
			c++;
		}
		*final = *final - 1;
		return 0;
	}
}

int main()
{
	TCidade lista[MAX_TAM];
	char vNome[21];
	int final, c;

	final = -1;
	while(1)
	{
		printf("Informe o nome da cidade (ou 'FIM' para encerar): \n");
		scanf("%s", lista[final+1].nome);

		if(strcmp(lista[final+1].nome, "FIM")==0)
			break;
		else
			final++;

		printf("Informe a populacao:\n");
		scanf("%d", &lista[final].pop);

		printf("informe a area:\n");
		scanf("%f", &lista[final].area);
	}
	if(final == -1){
		printf("Nenhum valor informado!\n");
		return 0;
	}
	printf("\n\nOs valores informados foram:\n");
	imprimir(lista,&final);

	printf("\n\nInforme o nome da cidade desejada(""nop"" para intemrromper):\n");
	scanf("%s", vNome);
	while(strcmp(vNome, "nop")){
		if(excluir(lista,vNome,&final)){
			printf("Exclusao não realizada!");
		}else{
			printf("Exclusao realizada com sucesso!\nLista atualizada:\n");
			imprimir(lista,&final);
		}
		printf("\n\nInforme o nome da cidade desejada(""nop"" para intemrromper):\n");
		scanf("%s", vNome);
	}

	return 0;
}
