#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int chico;
void find(char *ourstr){
    int a,b=0;
    for(a=0;ourstr[a] != '\0';a++){
        if(ourstr[a] == '<'){
            b++;
        }
        if(ourstr[a] == '>'){
            if(b>0){
                chico++;
                b--;
            }
        }
    }
}

int main(){
    int a,casos;
    char equa[1005];
    scanf("%d",&casos);
    fgets(equa,1004,stdin);
    for(a=0;a<casos;a++){
        fgets(equa,1004,stdin);
        chico = 0;
        // flag = strlen(equa);
        // equa[flag] = '\0';
        find(equa);

        printf("%d\n", chico);
    }
    return 0;
}
