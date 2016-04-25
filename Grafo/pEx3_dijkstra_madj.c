/*	
	Menor caminho em MATRIZ DE ADJACENCIAS usando algoritmo de DJIKSTRA.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TRUE	1
#define FALSE	0

#define MAX_VERTICES 1000
#define MAX_ARESTAS  1000
#define INFINITO     10001

char vertices[MAX_VERTICES];
short int arestas[MAX_VERTICES][MAX_VERTICES];

int dijkstra( short int, short int, short int );

int main()
{	short int V, A, O, D, P, i, j, C, caso = 0;

	while( scanf( "%hd %hd", &V, &A ) && !( V==0 && A==0 ) )
	{	/* Inicializando a matriz de adj com infinito */
		for( i=0; i<V; i++ )
			for( j=0; j<V; j++ )
				arestas[i][j] = INFINITO;
		
		/* Recebendo as arestas que descrevem o grafo */
		for( i=0; i<A; i++ )
		{	scanf( "%hd %hd %hd", &O, &D, &P );
			arestas[O-1][D-1] = P;
		}
		
		printf( "Caso %d\n", ++caso );
		
		/* Processando as consultas a realizar sobre o grafo */
		scanf( "%hd", &C );
		for( i=0; i<C; i++ )
		{	scanf( "%hd %hd", &O, &D );
			printf( "O menor custo entre os locais %hd e %hd eh %d.\n", O, D, 
					dijkstra( V, O-1, D-1 ) );
		}
		printf( "\n" );
	}

	return 0;
}

int dijkstra( short int V, short int O, short int D )
{	short int Distancias[MAX_VERTICES], i, j, menor, proximo;

	/* Marcando os vertices como ainda nao incluidos no caminho minimo */
	memset(vertices, FALSE, V );
	
	/* Inicializando os array de distancias com infinito */
	for(i=0; i<V; i++ )
		Distancias[i] = INFINITO;
	
	/* Para atingir o vertice de origem a distancia eh zero, obviamente */
	Distancias[O] = 0;
	
	for( i=0; i<V; i++ )
	{	/* Determinando o proximo vertice a computar no caminho minimo */
		menor = INFINITO;
		for( j=0; j<V; j++ )
			if( vertices[j] == FALSE && Distancias[j]<menor )
			{	menor = Distancias[j];
				proximo = j;
			}
		
		vertices[proximo] = TRUE;	/* Marcando esse vertice da vez */
		
		/* Computando as distancias acumuladas a partir do vertice selecionado */
		for( j=0; j<V; j++ )
			if( arestas[proximo][j] != INFINITO )
				if( Distancias[proximo]+arestas[proximo][j] < Distancias[j] )
					Distancias[j] = Distancias[proximo]+arestas[proximo][j];
	}
	
	return Distancias[D];
}
