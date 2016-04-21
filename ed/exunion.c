#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Enumeração P para pessoa e E para empresa
typedef enum c{
		P=1, E
	}clientes;

//Estrutura de Datas
typedef struct d{
	int dia;
	int mes;
	short ano;
}Data;

//Estrutura de endereços
typedef struct x{
	char Logradouro[51];
	char Complmento[31];
	char Bairro[21];
	char Cidade[21];
	int CEP;
	char Estado[3];
}Local;


//Tipos Clientes
typedef struct e{
	char RSocial[51];
	char CNPJ[19];
	char IEstadual[15];
	float LimiteC;
}Juridica;

typedef struct p{
	char Nome[41];
	char Cpf[15];
	char Sexo;
	Data Nascimento;
	float LimiteC;
}Fisica;


//Nossa querida UNION
typedef union i{
	Fisica Pessoa;
	Juridica Empresa;
}Cliente;

//Nossa queria Struct
typedef struct {
	clientes Tipo;
	Data Cadastro;
	Local Endereco;
	Cliente Classe;
}Cadastro;

int main(){
	char TipoEntrada,trash[5];
	Cadastro CLIENTE;

	printf("Insica o tipo de Cliente para gravacao: ""P""-Pessoa Fisica	""E""-Pessoa Juridica\n");
	scanf("%c", &TipoEntrada);
	gets(trash);

	if (TipoEntrada == 'P' || TipoEntrada == 'p'){
		CLIENTE.Tipo = P;
		printf("Insira o Nome\n");
		fgets(CLIENTE.Classe.Pessoa.Nome, 40, stdin);
		puts(CLIENTE.Classe.Pessoa.Nome);
		scanf("%d",&CLIENTE.Cadastro.dia);
		printf("%d\n",CLIENTE.Cadastro.dia);
	}else{
		if(TipoEntrada == 'E' || TipoEntrada == 'e'){
			CLIENTE.Tipo = E;
			fgets(CLIENTE.Classe.Empresa.RSocial,50,stdin);
			puts(CLIENTE.Classe.Empresa.RSocial);
		}
	}


	return 0;
}
