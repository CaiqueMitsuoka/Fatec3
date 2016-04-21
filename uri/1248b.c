#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int comp(void const *a, void const *b){
    return (int)((char*)a - (char*)b);
}

void limpaenter(char *limpo){
    int a=0;
    for(;limpo[a] != '\n';a++);
    limpo[a] = '\0';
}

void compdieta(char *dieta, char *ref){
    int tamdieta = strlen(dieta), tamref = strlen(ref),a,j;

    for(a=0;a<tamdieta;a++){
        for(j=0;j<tamref;j++){
            if(dieta[a] != -1 && dieta[a] == ref[j]){
                dieta[a] = ref[j] = -1;
            }
        }
    }
}

void bubble(char *vet, int tam){
    int i,j;
    char temp;
    for(i=0;i<tam - 1;i++){
        for(j=0; j<tam - (i + 1);j++){
            if(vet[j] > vet[j+1]){
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j + 1] = temp;
            }
        }
    }
}

char* arrumarponteiro(char *vet){
    int a=0;
    for(;vet[a] == -1;a++);
    return &vet[a];
}

int main(){
    int casos,a,j,k,tam,tam1;
    char dieta[30],ref1[30],ref2[30],trash[5],reft[65],*ndieta,*nref ;
    scanf("%d", &casos);
    fgets(trash,4,stdin);
    for(a=0;a<casos;a++){
        fgets(dieta,27,stdin);
        limpaenter(dieta);

        fgets(ref1,27,stdin);
        limpaenter(ref1);

        fgets(ref2,27,stdin);
        limpaenter(ref2);
        sprintf(reft,"%s%s",ref1,ref2);

        compdieta(dieta,reft);

        bubble(dieta,strlen(dieta));
        bubble(reft,strlen(reft));

        ndieta = arrumarponteiro(dieta);
        nref = arrumarponteiro(reft);

        if(nref[0]){
            printf("CHEATER\n");
        }else{
            printf("%s\n", ndieta);
        }

        // printf("%s %s\n",ndieta,nref);
    }

    return 0;
}
