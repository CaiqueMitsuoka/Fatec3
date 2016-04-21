#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int comp(void const *a, void const *b){
    return (int)((char*)b - (char*)a);
}

int compdieta(char *dieta, char *ref){

    int tamdieta = strlen(dieta), tamref = strlen(ref),a,j;

    for(a=0;a<tamdieta;a++){
        for(j=0;j<tamref;j++){
            if(dieta[a] != -1 && dieta[a] == ref[j]){
                dieta[a] = ref[j] = -1;
            }
        }
    }

    return 0;
}

int printdoido(char *eae){
    if(eae[0]){
        printf("%s\n",eae);
    }else{
        printf("TEM NADA NÃO VEI\n");
    }
    return 0;
}

int limpar(char *clean){
    int a=0;
    while(clean[a] != 0){
        if(clean[a] == -1){
            clean[a] = '\0';
            break;
        }
        a++;
    }
    return 0;
}

void limpaenter(char *limpo){
    int a=0;
    for(;limpo[a] != '\n';a++);
    limpo[a] = '\0';
}

int main(){
    int casos,a,j,k,tam,tam1;
    char dieta[28],ref1[28],ref2[28],trash[5];
    scanf("%d", &casos);
    fgets(trash,1,stdin);
    for(a=0;a<casos;a++){
        fgets(dieta,27,stdin);
        limpaenter(dieta);

        tam = strlen(dieta);
        qsort(dieta,strlen(dieta),sizeof(char),comp);


        fgets(ref1,27,stdin);
        limpaenter(ref1);

        compdieta(dieta,ref1);
        tam1 = strlen(ref1);
        qsort(ref1,strlen(ref1),sizeof(char),comp);


        fgets(ref2,27,stdin);
        limpaenter(ref2);

        compdieta(dieta,ref2);
        tam1 = strlen(ref2);


        //printf("aqui\n");
        qsort(ref2,tam1-1,sizeof(char),comp);



        limpar(ref1);
        limpar(ref2);
        limpar(dieta);
        printf("ref1:");
        printdoido(ref1);
        printf("ref2:");
        printdoido(ref2);
        printf("dieta:");
        printdoido(dieta);
        // printf("\n");


    }
    return 0;
}
