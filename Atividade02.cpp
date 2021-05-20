//Atividade02
#include <stdio.h>
#include <stdlib.h>
typedef struct tipo_pilha{
	int dados[tamanho];
	int ini;
	int topo;
}tipo_pilha;

tipo_pilha pilha;

void foo(int elemento){
	if(pilha.topo == tamanho){
		printf("Erro,\n");
		system("pause");
	}else{
		pilha.dados[pilha.topo] = elemento;
		pilha.topo++;
	}
}

int main (void){
foo();
}
