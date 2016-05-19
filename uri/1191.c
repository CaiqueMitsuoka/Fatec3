#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct a{
    char letra;
    struct a *prox;
}TITEM;

typedef struct {
    struct a *inicio;
}TLISTA;

void addstack(TLISTA *lista, char letra){
    TITEM *novo = (TITEM*)malloc(sizeof(TITEM));
    novo->letra = letra;
    novo->prox = lista->inicio;
    lista->inicio  = novo;
}

void imprimelist(TLISTA *lista) {
    TITEM *aux = lista->inicio;
    while(aux != NULL){
        printf("%c", aux->letra);
        aux = aux->prox;
    }
    printf("\n");
}
int makepost(char *pre, char *in, TLISTA *lista){
    char PreOrd[30], InOrd[30];
    char tam = strlen(pre), a,b;
    if(tam == 0){
        return 0;
    }else{
        addstack(lista, pre[0]);

    }
    ///procurar meio da in
    for(a=0;a < tam && in[a] != pre[0];a++);
    //marcar meio da in
    in[a] = '\0';
    // primeira metade de ta in no InOrd
    sprintf(InOrd, "%s", in);
    printf("in ant: %s\n", InOrd);
    //vendo tamanho ta in depois do meio
    tam = strlen(in);
    for(b=0;b<tam;b++){
        PreOrd[b] = pre[b+1];
    }
    PreOrd[b] = '\0';
    printf("pre ant: %s\n", PreOrd);

    makepost(PreOrd, InOrd, lista);

    tam = strlen(&in[a+1]);
    sprintf(InOrd, "%s", &in[a+1]);
    printf("in dpo: %s\n", InOrd);
    for(b=0;b<tam;b++){
        PreOrd[b] = pre[b+1+tam];
    }
    PreOrd[b] = '\0';
    printf("pre dpo: %s\n", PreOrd);

    makepost(PreOrd, InOrd, lista);
    return 0;
}

int main(){
    char PreOrd[30], InOrd[30];
    TLISTA *Post;
    while(scanf("%s", PreOrd) != EOF){
        scanf("%s", InOrd);
        Post = (TLISTA*)malloc(sizeof(TLISTA));
        Post->inicio = NULL;
        makepost(PreOrd, InOrd, Post);
        imprimelist(Post);
    }
    return 0;
}
