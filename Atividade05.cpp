//Atividade05
#include <stdio.h>
#include <stdlib.h>

typedef struct t_p{
	char nome;
	int idade;
	float peso;
}t_pessoa;


int main (){
	t_pessoa lista[10];
	int i = 9;
	printf("Insira um n�mero: \n");
	scanf("%f",&lista[i].peso);
}
