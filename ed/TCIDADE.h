struct regCid	{	char nome[21];
					int pop;
					float area;
				};
typedef struct regCid TCidade;

typedef struct { TCidade lista[MAX_TAM]; int final, totPop; } TLista;
