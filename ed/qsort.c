#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int compare(const void *p1,const void *p2){
	int *a = (int*)p1, *b = (int*)p2;
	return *a - *b;
}

int main(){
	int vet[8] = {2,5,8,9,4,6,2,6}, total = 8,a;
	qsort(vet,total,sizeof(int),compare);
	printf("aqui foi lek\n");
	for(a=0;a<total;a++){
		printf("%d\n",vet[a]);
	}
	return 0;
}