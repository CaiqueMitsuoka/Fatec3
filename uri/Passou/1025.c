#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmpint(void const *a, void const *b){
    return *(int*)a - *(int*)b;
}

int main(){
    int NVet, NCase, vet[100050], i, j, item, chave, tmp, a, casos=0, item2, *pont;

    scanf("%d %d", &NVet, &NCase);

    while(NVet != 0 && NCase != 0){
        for(a=0;a<NVet;a++){
            scanf("%d",&vet[a]);
        }

        qsort(vet,NVet,sizeof(int),cmpint);

        casos++;
        printf("CASE# %d:\n",casos);

        for(a=0;a<NCase;a++){
            scanf("%d",&chave);

            pont = (int*)bsearch(&chave,vet,NVet,sizeof(int),cmpint);

            if(pont == NULL){
                printf("%d not found\n", chave);
            }else{
                item = (int)(pont - vet);
                item2 = item - 1;
                while(item2 >= 0 && vet[item2] == chave) {
                    item = item2;
                    item2 = item2 - 1;
                }

                printf("%d found at %d\n",chave ,item + 1);
            }

        }
        scanf("%d %d", &NVet, &NCase);
    }

    return 0;
}
