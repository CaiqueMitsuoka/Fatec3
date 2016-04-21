#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
    int num;
    int den;
}FRAC;

FRAC soma(FRAC f1, FRAC f2){
    FRAC result;
    result.num = f1.num*f2.den + f2.num*f1.den;
    result.den = f1.den * f2.den;
    return result;
}

int mdc(int a, int b){
    int resto;
    a = fabs(a);
    b = fabs(b);
    while(b != 0){
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

FRAC fmdc(FRAC f1){
    int Mdc;
    FRAC result;
    Mdc = mdc(f1.num,f1.den);
    result.num = f1.num / Mdc;
    result.den = f1.den / Mdc;
    return result;
}

int main(){
    FRAC f1,f2,result;
    scanf("%d %d %d %d", &f1.num, &f1.den, &f2.num, &f2.den);
    result =  fmdc(soma(f1,f2));
    printf("%d %d",result.num, result.den);
    return 0;
}
