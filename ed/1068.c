#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void find(char *ourstr){
    int a,b;
    for(a=0;ourstr[a] != '\0';a++){
        if(ourstr[a] == '('){
            for(b=a+1;ourstr[b] != '\0';b++){
                if(ourstr[b] == '('){
                    find(&ourstr[b]);
                }
                if(ourstr[b] == ')' && ourstr[a] == '('){
                    ourstr[b] = '%';
                    ourstr[a] = '%';
                    break;
                }
            }
        }
    }
}

int main(){
    int flag, a;
    char equa[1005];
    while(fgets(equa,1004,stdin) != NULL){
        flag = strlen(equa);
        equa[flag] = '\0';
        find(equa);
        flag = 1;
        for(a=0;equa[a] != '\0';a++){
            if(equa[a] == '(' || equa[a] == ')'){
                printf("incorrect\n");
                flag = 0;
                break;
            }
        }
        if(flag){
            printf("correct\n");
        }

        printf("%s", equa);
    }
    return 0;
}
