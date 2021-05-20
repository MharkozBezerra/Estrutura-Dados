//Atividade08
#include <stdio.h>
#include <stdlib.h>

int main (){
 float *ptr;
 printf("Endereco: %p \n\n", ptr);
 ptr =(float *) malloc(4);
 printf("Endereço: %p \n Valor: %d \n\n",ptr, *ptr);
}
