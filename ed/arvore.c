#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct osmlkquechapa{
    struct osmlkquechapa *esq;
    int num;
    struct osmlkquechapa *dir;
}TNODE;

void addtree(TNODE *root, int num){
    TNODE *novo = (TNODE*)malloc(sizeof(TNODE));
    novo->num = num;
    novo->esq = novo->dir = NULL;
    if(root == NULL){
        root = novo;
    }else{
        if(num <= root->num){
            if(root->esq != NULL){
                addtree(root->esq,num);
            }else{
                root->esq = novo;
            }
        }else{
            if(root->dir != NULL){
                addtree(root->dir,num);
            }else{
                root->dir = novo;
            }
        }
    }
}

void printarvre(TNODE *node, int profundidade){
    int a;
    for(a=0;a<profundidade;a++){
        printf("\t");
    }
    printf("%d\n", node->num);
    if(node->esq != NULL){
        printarvre(node->esq,profundidade + 1);
    }
    if(node->dir != NULL){
        printarvre(node->dir,profundidade + 1);
    }
}

int contanode(TNODE *node){
    if(node != NULL){
        return 1 + contanode(node->esq) + contanode(node->dir);
    }else{
        return 0;
    }
}

int contaaltura(TNODE *node){
    int esq,dir;
    if(node != NULL){
        esq = contaaltura(node->esq);
        dir = contaaltura(node->dir);
        if(dir > esq){
            return dir + 1;
        }else{
            return esq + 1;
        }
    }else{
        return 0;
    }
}

int contapar(TNODE *node){
    if(node == NULL){
        return 0;
    }else{
        if(node->num % 2){
            return contapar(node->esq) + contapar(node->dir);
        }else{
            return 1 + contapar(node->esq) + contapar(node->dir);
        }
    }
}

int contaimpar(TNODE *node){
    if(node == NULL){
        return 0;
    }else{
        if(node->num % 2){
            return 1 + contapar(node->esq) + contapar(node->dir);
        }else{
            return contapar(node->esq) + contapar(node->dir);
        }
    }
}

int main(){
    int num;
    TNODE *root = (TNODE*)malloc(sizeof(TNODE));
    scanf("%d", &num);
    root->num = num;
    root->esq = root->dir = NULL;
    scanf("%d", &num);
    while(num){
        addtree(root,num);
        scanf("%d", &num);
    }
    printarvre(root,0);
    printf("arvore tem %d nos!\n", contanode(root));
    printf("arvore tambem tem %d de altura\n", contaaltura(root));
    printf("temos %d numeros pares\n", contapar(root));
    printf("temos %d numeros impares\n", contaimpar(root));
}
