

/*==============================================================
 == Curso: Análise e Desenvolvimento de Sistemas - Unicesumar ==
 == Aluno:Antonio Marcos da Silva Bezerra ra: 19123576-5 =======
 ===============================================================
 == Atividade: MAPA - ADS - ESTRUTURA DE DADOS I - 52/2021 =====
 ===============================================================
*/
/*==============================================================
 [ok] - Ao adiiconar o trabalho, o último a entrar é o último a sair.
 [ok] - Ao adicionar o trabalho, o primeiro a entrar é o primeiro a sair.
 [ok] - Dados a ser adicionados:
	[ok] - o RA do aluno
	[ok] - o Nome do arquivo
	[ok] - o Extensão do arquivo
	[ok] - o Matrícula do professor responsável pela correção
 [ok] - ao excluir um elemento,  sempre irá excluir o primeiro elemento da fila.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>   // utilizar padrão pt-br e derivados da lingua.
#define tamanho 5     //Define 5 como valor
#include <stdbool.h> //Adicionado para utilizar valores true / false
typedef struct cadastro {
	char RA[15];
	char arquivo[15];
	char ext[5];
	char matricula[15];
} cadastro;

typedef struct fila {
	cadastro dados[tamanho];
	int ini;
	int fim;
} fila;

fila fila_cadastro;

void enfileira() {
	if(fila_cadastro.fim == tamanho) {
		printf("Não é possível enfileirar itens!\n\n\n\n");
	} else {
		printf("Digite o RA: \n");
		scanf(" %s", fila_cadastro.dados[fila_cadastro.fim].RA);
		setbuf(stdin,NULL);

		printf("Digite o nome do Arquivo: \n");
		scanf(" %s", fila_cadastro.dados[fila_cadastro.fim].arquivo);
		setbuf(stdin,NULL);

		printf("Digite a Extensão do Arquivo: \n");
		scanf(" %s", fila_cadastro.dados[fila_cadastro.fim].ext);
		setbuf(stdin,NULL);

		printf("Digite a Matrícula: \n");
		scanf(" %s", fila_cadastro.dados[fila_cadastro.fim].matricula);

		fila_cadastro.fim++;
	}
}

void desenfileira() {
	if(fila_cadastro.fim == fila_cadastro.ini) {
		printf("Não é possível desenfileirar itens!\n");
	} else {
		int i;
		for(i = 0; i < fila_cadastro.fim; i++) {
			strcpy(fila_cadastro.dados[i].RA, fila_cadastro.dados[i+1].RA);
			strcpy(fila_cadastro.dados[i].arquivo, fila_cadastro.dados[i+1].arquivo);
			strcpy(fila_cadastro.dados[i].ext, fila_cadastro.dados[i+1].ext);
			strcpy(fila_cadastro.dados[i].matricula, fila_cadastro.dados[i+1].matricula);
		}
		fila_cadastro.fim--;
	}
}

void esvaziar() {
	fila_cadastro.fim = 0;
	if(fila_cadastro.ini == fila_cadastro.fim) {
		printf("Esvaziando Fila...!\n\n");
	}
}

void mostrar_fila() {
	if(fila_cadastro.ini == fila_cadastro.fim) {
		printf("Fila Vazia!! Insira Elementos.\n\n\n\n");
	} else {
		printf("Imprimindo FILA.\n");
		printf("---------------------------\n");
		if(fila_cadastro.fim == tamanho) {
			printf("-----------\n");
			printf("Fila Cheia!\n");
			printf("-----------\n");
		}
		int i;
		for(i= 0; i < fila_cadastro.fim; i++) {
			printf("Posição: 0%d\n\n", i + 1);
			printf("RA: %s\n", fila_cadastro.dados[i].RA);
			printf("Arquivo: %s\n", fila_cadastro.dados[i].arquivo);
			printf("Extensão: %s\n", fila_cadastro.dados[i].ext);
			printf("Matrícula: %s\n", fila_cadastro.dados[i].matricula);
			printf("---------------------------\n");
		}
	}
}
//O programa deve ter um menu principal em forma de laço de repetição que atenda aos seguintes requisitos:
int main() {
	setlocale(LC_ALL, "portuguese");
	int opt;
	bool sair;
	//O menu sempre deve imprimir o conteúdo da fila (do início em direção ao fim);
	mostrar_fila();
	//Após a impressão do conteúdo da fila, o usuário deve ser informado de que pode realizar as seguintes operações:
	while (sair != true) {
		//o    Inserir um elemento na fila;
		printf("----------Escolha uma das opções abaixo-----------\n");
		printf("1. Adicionar novo elemento\n");
		//o    Remover um elemento da fila;
		printf("2. Remover elemento\n");
		//o    Esvaziar a fila;
		printf("3. Esvaziar Fila\n");
		//o    Encerrar o programa.
		printf("0. Sair\n");
		printf("Opção:\n");
		scanf("%d", &opt);
		system("cls");
		setbuf(stdin,NULL);

		switch (opt) {
			case 0:
				printf("0. Saindo do programa...\n\n");
				sair = true;
				break;
			case 1:
				printf("1. Adicionar novo Elemento.\n\n");
				enfileira();
				system("cls");
				mostrar_fila();
				break;
			case 2:
				printf("2. Remover Elemento.\n\n");
				desenfileira();
				mostrar_fila();
				break;
			case 3:
				printf("3. Esvaziar Fila.\n\n");
				esvaziar();
				mostrar_fila();
				break;
			default:
				printf("Ops!!!\n Acho que você digitou algo incorreto!\n\n\n\n");
				break;
		}

	}

	return 0;
}
