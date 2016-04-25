#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 10000
#define MAXA 10000

typedef struct {
    int vert;
    int peso;
}TVertList;

typedef struct{
    int adj[MAXV];
    TVertList vert[MAXV][MAXA];
}TLstAd;

typedef struct{
    TLstAd lista;
    int nVert;
    int nAresta;
}TGraph;

int main(){
    return 0;
}
