#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct groot{
    struct groot *esq;
    int cara;
    struct groot *dir;
}TNODE;

typedef struct{
    TNODE *root;
    int eae;
}TTREE;

int spc;

void addnode(TTREE * arvre, int *cara){
    TNODE *novo = (TNODE*)malloc(sizeof(TNODE)), *aux;
    novo->cara = *cara;
    novo->dir = NULL;
    novo->esq = NULL;
    if(arvre->root == NULL){
        arvre->root = novo;
    }else{
        aux = arvre->root;
        while(1){
            if(aux->cara > *cara){
                if(aux->esq != NULL){
                    aux = aux->esq;
                }else{
                    aux->esq = novo;
                    break;
                }
            }else{
                if(aux->dir != NULL){
                    aux = aux->dir;
                }else{
                    aux->dir = novo;
                    break;
                }
            }
        }
    }
}

void createPre(TNODE *node){
    if(node != NULL){
        if(spc){
            printf(" ");
        }
        spc=1;
        printf("%d", node->cara);
        createPre(node->esq);
        createPre(node->dir);
    }
}
void CreateIn(TNODE *node){
    if(node != NULL){
        CreateIn(node->esq);
        if(spc){
            printf(" ");
        }
        spc=1;
        printf("%d", node->cara);
        CreateIn(node->dir);
    }
}
void CreatePost(TNODE *node){
    if(node != NULL){
        CreatePost(node->esq);
        CreatePost(node->dir);
        if(spc){
            printf(" ");
        }
        spc=1;
        printf("%d", node->cara);
    }
}
TNODE* searchnode(TTREE *toku, int* wanted){
    TNODE *aux = toku->root;
    while(1){
        if(aux == NULL || aux->cara == *wanted){
            return aux;
        }else{
            if(aux->cara > *wanted){
                aux = aux->esq;
            }else{
                aux = aux->dir;
            }
        }
    }
}
void corrigenode(TNODE *quem, TNODE *pai, TNODE *novo){
    if(pai->esq == quem){
        pai->esq = novo;
    }else{
        pai->dir = novo;
    }
}

TNODE* removenode(TTREE *toku, int* wanted){
    TNODE *aux = toku->root, *pai = NULL ,*aux2 = NULL, *pai2;
    while(1){
        if(aux == NULL || aux->cara == *wanted){
            printf("*%d*", *wanted);
            if(aux == NULL){
                return NULL;
            }
            if(aux->esq == NULL && aux->dir == NULL){
                corrigenode(aux,pai,NULL);
                return aux;
            }
            if(aux->esq == NULL || aux->dir == NULL){
                if(aux->esq == NULL){
                    corrigenode(aux,pai,aux->dir);
                }else{
                    corrigenode(aux,pai,aux->esq);
                }
                return aux;
            }
            pai2 = aux;
            aux2 = aux->dir;
            while(aux2->esq != NULL){
                pai2 = aux2;
                aux2 = aux2->esq;
            }
            aux->cara = aux2->cara;
            corrigenode(aux2, pai2, aux2->dir);
            return aux;
        }else{
            pai = aux;
            if(aux->cara > *wanted){
                aux = aux->esq;
            }else{
                aux = aux->dir;
            }
        }
    }
}
int main(){
    char comando[10];
    int who;
    TTREE *pinheiro = (TTREE*)malloc(sizeof(TTREE));
    int tam;
    pinheiro->root = NULL;
    while(scanf("%s", comando) != EOF){
        tam = strlen(comando);
        if(tam != 1){
            spc = 0;
            if(strcmp(comando, "PREFIXA") == 0){
                createPre(pinheiro->root);
                printf("\n");
            }else if(strcmp(comando, "INFIXA") == 0){
                CreateIn(pinheiro->root);
                printf("\n");
            }else if(strcmp(comando, "POSFIXA") == 0){
                CreatePost(pinheiro->root);
                printf("\n");
            }
        }else{
            switch(comando[0]){
                case 'I':
                    scanf("%d", &who);
                    addnode(pinheiro , &who);
                break;
                case 'P':
                    scanf("%d", &who);
                    if(searchnode(pinheiro, &who) == NULL){
                        printf("%d nao existe\n", who);
                    }else{
                        printf("%d existe\n", who);
                    }
                break;
                case 'R':
                    scanf("%d", &who);
                    removenode(pinheiro, &who);
                break;
            }
        }
    }


    return 0;
}
