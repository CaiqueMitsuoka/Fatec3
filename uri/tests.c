#include <stdio.h>

int main(){
    int a;
    char who[5];
    scanf("%s",who);
    who[1] = -1;
    a=-1;
    do{
        a++;
        printf("%d   ",who);

    }while(who[a]);

    printf("\n%s\n", who);
    return 0;
}
