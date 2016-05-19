//Caique Hitoshi Mitsuoka 0030481511006
//Felipe Richter Lapolla Inocencio 0030481511013

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilha{
	char parenteses;
	struct pilha *proximo;
}Pilha;

typedef struct descritor{
	Pilha *topo;
	int qtdeElementos;
}DPilha;

void push(DPilha *descritor,char *string);
int pop(DPilha *descritor, char caracter);

int main(){
	DPilha *descritor = (DPilha *) malloc(sizeof(descritor));
	int resultado;
	char string[21];

	while(scanf("%s", string) != EOF){
		descritor->topo = NULL;
		descritor->qtdeElementos = 0;

		push(descritor, string);
		if(descritor->qtdeElementos == 0)
			printf("Balanceado\n");
		else
			printf("Não Balanceado\n");
	}

	return 0;
}

void push(DPilha *descritor, char *string){
	int i, retorno;
	char caracter;
	Pilha *aux;
	descritor->qtdeElementos = 0;

	for(i=0;i<strlen(string);i++){
		if(string[i] == '(' || string[i] == '{' || string[i] == '['){
			aux = (Pilha *) malloc(sizeof(Pilha));
			aux->parenteses = string[i];
			aux->proximo = descritor->topo;

			descritor->topo = aux;
			descritor->qtdeElementos++;
		}
		else if(string[i] == ')' || string[i] == ']' || string[i] == '}'){
			caracter = string[i];
			retorno = pop(descritor, caracter);
		}
		if(retorno == 1){
			break;
		}
	}
}
int pop(DPilha *descritor, char caracter){
	Pilha *aux;

	if(descritor->qtdeElementos > 0){
		switch(caracter){
			case ')':
				if(descritor->topo->parenteses == '('){
				aux = descritor->topo;
				descritor->topo = descritor->topo->proximo;
				descritor->qtdeElementos--;

				free(aux);
				}
				else
				return 1;
			break;
			case '}':
				if(descritor->topo->parenteses == '{'){
				aux = descritor->topo;
				descritor->topo = descritor->topo->proximo;
				descritor->qtdeElementos--;

				free(aux);
				}
				else
				return 1;
			break;
			case ']':
				if(descritor->topo->parenteses == '['){
				aux = descritor->topo;
				descritor->topo = descritor->topo->proximo;
				descritor->qtdeElementos--;

				free(aux);
				}
				else
				return 1;
			break;	
		}
	}
	else if(descritor->qtdeElementos<=0){
		descritor->qtdeElementos--;
		return 1;
	}
	else
		return 0;
}
