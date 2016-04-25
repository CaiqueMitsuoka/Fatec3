#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int casos,j;
    char trash[5],nossa[105],met,met1[51],met2[51],a,b,tam,b2,temp,c;
    scanf("%d", &casos);
    fgets(trash,5,stdin);
    for(j=0;j<casos;j++){
        //printf("\n##############CASO:%d##############\n",j);
        fgets(nossa,105,stdin);
        tam = strlen(nossa);
        nossa[tam - 1] = '\0';

        tam = strlen(nossa);
        tam--;
        met = tam/2;
        // if(tam % 2){
        //     met++;
        // }
        b = met+1;
        c = met;
        for(a=0;a<met/2;a++){
            temp = nossa[c];
            nossa[c] = nossa[a];
            nossa[a] = temp;
            c--;

            temp = nossa[tam - a];
            nossa[tam - a] = nossa[b];
            nossa[b] = temp;
            b++;
        }
        printf("%s\n",nossa);
    }
    return 0;
}
