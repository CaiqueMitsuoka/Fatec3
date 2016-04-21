#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INFINITE 32768
#define MEMBER 1
#define NONMEMBER 0
#define MAXNODES 50

typedef struct graph GRAPH;
typedef struct head HEAD;
typedef struct node NODE;
typedef struct pqueue PQUEUE;
typedef struct nodepqueue NODEPQUEUE;
void heapfy_down (GRAPH * g, PQUEUE *pq, int i);
void update_pqueue (GRAPH *g, PQUEUE *pq, int inode);
NODEPQUEUE remove_pqueue (GRAPH *g, PQUEUE *pq);
void heapfy_up (GRAPH * g, PQUEUE *pq, int i);
void insert_pqueue (GRAPH *g, PQUEUE *pq, int inode);

struct head {

    // armazena 1 se vértice já foi incluído em PERM ou 0 em caso contrário
    int perm;

    // nó precedente no caminho de custo mínimo
    int path;

    // posicao do vértice na fila de prioridades
    int posQueue;

    // distância mínima (atual se perm=0 ou final se perm=1) a partir do vértice de origem
    int minDist;

    // ponteiro para lista de nós adjacentes
    NODE *adj;

};

// nós das listas de adjacências
struct node {

    //índice do vértice adjacente
    int arc;

    //peso da aresta
    int dist;

    //próximo nó adjacente da lista;
    NODE *next;

};

struct nodepqueue {

    // vértice
    int arc;

    // distância
    int dist;

};

struct pqueue {

    NODEPQUEUE elem[MAXNODES + 1];

    // índice do último elemento da fila (ou qtde. de elementos na fila)
    int last;

};

struct graph {

    // vetor de cabeças
    HEAD heads[MAXNODES];

};

GRAPH* init_graph () {

    GRAPH *gTemp = (GRAPH *) malloc(sizeof(GRAPH));

    for (int i = 0; i < MAXNODES; i++) {

        gTemp->heads[i].adj = NULL;

    }

    return gTemp;

}

void insert_pqueue (GRAPH *g, PQUEUE *pq, int inode) {

    // insere o elemento no final da fila de prioridades
    pq->last = pq->last + 1;

    //armazena a distância do vértice que está sendo incluído na fila
    pq->elem[pq->last].arc = inode;
    pq->elem[pq->last].dist = g->heads[inode].minDist;

    // atualiza posQueue o que me permite saber onde um vértice está na fila
    g->heads[inode].posQueue = pq->last;

    // refaz o heap ascendente
    heapfy_up (g, pq, pq->last);

}

void update_pqueue (GRAPH *g, PQUEUE *pq, int inode) {

    // refaz o heap ascendente a partir da posicao de inode
    heapfy_up (g, pq, g->heads[inode].posQueue);

}

NODEPQUEUE remove_pqueue (GRAPH *g, PQUEUE *pq) {

    NODEPQUEUE aux;

    if (pq->last > 0) {

        // armazena o primeiro elemento da fila de prioridades
        aux = pq->elem[1];
        change(g, pq, 1, pq->last);

        pq->last = pq->last - 1;

        heapfy_down (g, pq, 1);

        return aux;

    }

    else {

        aux.arc = -1;

        return aux;

    }

}

void heapfy_up (GRAPH * g, PQUEUE *pq, int i){
    int father, childLeft, childRight, smallest;

    father = i / 2;

    if (father > 0) {

        childLeft = father * 2;
        childRight = father * 2 + 1;

        if (childLeft <= pq->last && pq->elem[childLeft].dist < pq->elem[father].dist)
            smallest = childLeft;
        else
            smallest = father;

        if (childRight <= pq->last && pq->elem[childRight].dist < pq->elem[smallest].dist)
            smallest = childRight;

        if (smallest != father) {

            change(g, pq, father, smallest);

            heapfy_up (g, pq, father);

        }
    }
}

void heapfy_down (GRAPH * g, PQUEUE *pq, int i){
    int childLeft, childRight, smallest;

    childLeft = i * 2;
    childRight = i * 2 + 1;

    if (childLeft <= pq->last && pq->elem[childLeft].dist < pq->elem[i].dist)
        smallest = childLeft;
    else
        smallest = i;
    if (childRight <= pq->last && pq->elem[childRight].dist < pq->elem[smallest].dist)
        smallest = childRight;

    if (smallest != i) {

        change(g, pq, i, smallest);
        heapfy_down (g, pq, smallest);
    }

}


void dijkstra (GRAPH *g, int s, int t)
{

    int newdist;
    int current; NODEPQUEUE currentn;
    NODE *aux;

    // cria fila de prioridades
    PQUEUE *pq = (PQUEUE *) malloc(sizeof(PQUEUE));

    // (re)inicializa dados usados pela fila de prioridade
    init_dijkstra (g, pq);

    //faz distância de s = 0 e o inclui na fila de prioridades
    g->heads[s].minDist = 0;
    insert_pqueue (g, pq, s);

    while (1)
    {

        // remove da fila de prioridades o elemento com menor distância/peso (O (log n))
        currentn = remove_pqueue (g, pq);
        current = currentn.arc;

        // quando fila de prioriedades está vazia ela retorna -1 e o algoritmo termina
        if (current == -1)
            break;

        // faz-se current pertencer a PERM
        g->heads[current].perm = 1;

        // atualiza, se necessário, as distâncias de todos os vértices adjacentes a current
        // que ainda não foram incluídos em PERM
        for (aux = g->heads[current].adj; aux; aux = aux->next)
        {

            if (g->heads[aux->arc].perm == 0) {

                newdist = g->heads[current].minDist + aux->dist;

                // atualiza distância se a atual distância do vértice é maior que a distância
                // passando por current
                if (g->heads[aux->arc].minDist > newdist) {

                    if (g->heads[aux->arc].minDist == INFINITE) {

                        g->heads[aux->arc].minDist = newdist;
                        g->heads[aux->arc].path = current;

                        //O (log n)
                        insert_pqueue (g, pq, aux->arc);
                    }

                    else {

                        g->heads[aux->arc].minDist = newdist;
                        g->heads[aux->arc].path = current;

                        //O (log n)
                        update_pqueue (g, pq, aux->arc);
                    }

                }

            }

        } /* fim for */

    } /* fim while */

    /* impressao do resultado ****************/

    if (g->heads[t].path == -1)
        printf ("\n\nCAMINHO NAO EXISTE\n\n");

    else {

        printf("\n\nRESULTADO: ");
        int caminho = t;
        printf("%d <- ", t);

        while (caminho != s)
        {
            printf("%d ", g->heads[caminho].path);
            caminho = g->heads[caminho].path;
            if (caminho != s)
                printf (" <- ");

        }

        printf("\n\ncusto: %d\n\n", g->heads[t].minDist);

    }
    /****************************************/

} /* fim dijkstra */
