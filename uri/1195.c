#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct groot{
    struct groot *esq;
    int num;
    struct groot *dir;
}TNODE;

typedef struct{
    TNODE *root;
    int eae;
}TTREE;

void addnode(TTREE * arvre, int *num){
    TNODE *novo = (TNODE*)malloc(sizeof(TNODE)), *aux;
    novo->num = *num;
    novo->dir = NULL;
    novo->esq = NULL;
    if(arvre->root == NULL){
        arvre->root = novo;
    }else{
        aux = arvre->root;
        while(1){
            if(aux->num > *num){
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
        printf(" %d", node->num);
        createPre(node->esq);
        createPre(node->dir);
    }
}
void CreateIn(TNODE *node){
    if(node != NULL){
        CreateIn(node->esq);
        printf(" %d", node->num);
        CreateIn(node->dir);
    }
}
void CreatePost(TNODE *node){
    if(node != NULL){
        CreatePost(node->esq);
        CreatePost(node->dir);
        printf(" %d", node->num);
    }
}
int main(){
    TTREE *toku = (TTREE*)malloc(sizeof(TTREE));
    int casos,a,nnode,num,b;
    toku->root = NULL;

    scanf("%d", &casos);
    for(a=1;a<=casos;a++){
        scanf("%d", &nnode);
        for(b=0;b<nnode;b++){
            scanf("%d", &num);
            addnode(toku,&num);
        }
        printf("Case %d:\n", a);
        printf("Pre.:");
        createPre(toku->root);
        printf("\n");
        printf("In..:");
        CreateIn(toku->root);
        printf("\n");
        printf("Post:");
        CreatePost(toku->root);
        printf("\n\n");
        toku->root = NULL;


    }
}
