#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int nota(char *nota){
    switch(*nota){
        case 'W':
            return 64;
        case 'H':
            return 32;
        case 'Q':
            return 16;
        case 'E':
            return 8;
        case 'S':
            return 4;
        case 'T':
            return 2;
        case 'X':
            return 1;
    }
}

int main(){
    int a=0,tam,comp,soma;
    char musica[202],trash[5];

    scanf("%s",musica);

    while(musica[0] != '*'){
        comp = 0;
        tam = strlen(musica);
        soma = 0;
        for(a=0;a<tam;a++){
            if(musica[a]== musica[0]){
                if(soma == 64){
                    comp++;
                    soma = 0;
                }else{
                    soma = 0;
                }
            }else{
                soma += nota(&musica[a]);
            }
        }
        printf("%d\n",comp);
        scanf("%s",musica);
    }
    return 0;
}
