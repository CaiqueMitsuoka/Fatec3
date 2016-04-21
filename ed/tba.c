#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tba3.c"

int main(){
  //TDA é uma abstração de dados e é usado como interface para um tipo mais complexo ou mal projetado
  //geralmente é feito em um fonte separado com a definição do tipo para que seja incluido no programa
  //e linkado quando gerado os codigos objetos de ambos os fonte.

  //exemplo das frações:
  //quando se tem operações entre frações, uma vez que você executar a divisão de todas as frações
  //você estaria carregando imprecisão desde a primeira até a ultima opção eacumulando-as
  //ou seja, é melhor criar um tipo abstrado para estas opeções e implemetaço de forma que seja necessario
  //apenas uma operações de divisãoao fim. sendo assim é elimidado a imprecisão de todas as operações tendo
  //até uma da ultima divisão


  //definições em outros arquivos("tba2.c" e "tba3.c")
  TRac v1,v2,soma,divi,sub,mult;
  printf("Informe o primeiro numero racional: \n");
  scanf("%d/%d",&v1.num,&v1.den);

  printf("Informe o segundo numero racional: \n");
  scanf("%d/%d",&v2.num,&v2.den);

  soma = fmdc(SomaRac(v1,v2));
  divi = fmdc(DiviRac(v1,v2));
  sub = fmdc(SubtraiRac(v1,v2));
  mult = fmdc(MultRac(v1,v2));
  printf("soma = %d / %d\nsub = %d / %d\ndiv = %d / %d\nmult = %d / %d\n",soma.num,soma.den,sub.num,sub.den,divi.num,divi.den,mult.num,mult.den);
  //printf("resultado: %d/%d\n", v3.num , v3.den);
  return 0;
}
