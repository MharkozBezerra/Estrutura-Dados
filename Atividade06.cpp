//Atividade06
#include <stdio.h>
#include <stdlib.h>

int main (){
int A = 10;
int *ptr = &A;
*ptr = 15;
printf("%d",A);
}
