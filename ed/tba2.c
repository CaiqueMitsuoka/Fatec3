#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tba3.c"

typedef struct {
    int num;
    int den;
}FRAC;

TRac SomaRac(TRac f1, TRac f2){
    TRac result;
    result.num = f1.num*f2.den + f2.num*f1.den;
    result.den = f1.den * f2.den;
    return result;
}

TRac SubtraiRac(TRac f1, TRac f2){
    TRac result;
    result.num = f1.num*f2.den - f2.num*f1.den;
    result.den = f1.den * f2.den;
    return result;
}

TRac MultRac(TRac f1, TRac f2){
    TRac result;
    result.num = f1.num*f2.num;
    result.den = f1.den*f2.den;
    return result;
}

TRac DiviRac(TRac f1, TRac f2){
    TRac result;
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

TRac fmdc(TRac f1){
    int Mdc;
    TRac result;
    Mdc = mdc(f1.num,f1.den);
    result.num = f1.num / Mdc;
    result.den = f1.den / Mdc;
    return result;
}
