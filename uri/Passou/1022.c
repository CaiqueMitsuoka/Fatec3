#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int num;
    int den;
}FRAC;

FRAC soma(FRAC f1, FRAC f2){
    FRAC result;
    result.num = f1.num*f2.den + f2.num*f1.den;
    result.den = f1.den * f2.den;
    return result;
}

FRAC sub(FRAC f1, FRAC f2){
    FRAC result;
    result.num = f1.num*f2.den - f2.num*f1.den;
    result.den = f1.den * f2.den;
    return result;
}

FRAC mult(FRAC f1, FRAC f2){
    FRAC result;
    result.num = f1.num*f2.num;
    result.den = f1.den*f2.den;
    return result;
}

FRAC divi(FRAC f1, FRAC f2){
    FRAC result;
    result.num = f1.num*f2.den;
    result.den = f2.num*f1.den;
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
    int casos,n1,n2,d1,d2,j;
    char op;
    FRAC f1,f2,result,sresult;

    scanf("%d", &casos);

    for(j=0;j<casos;j++){
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
        f1.num = n1;
        f1.den = d1;
        f2.num = n2;
        f2.den = d2;
        switch (op) {
            case '+':
                result = soma(f1,f2);
                break;
            case '-':
                result = sub(f1,f2);
                break;
            case '*':
                result = mult(f1,f2);
                break;
            case '/':
                result = divi(f1,f2);
                break;
        }
        sresult = fmdc(result);
        printf("%d/%d = %d/%d\n", result.num, result.den, sresult.num, sresult.den);
        //printf("\n%d/%d\n%c\n%d/%d\n",n1,d1,op,n2,d2);
    }
    return 0;
}
