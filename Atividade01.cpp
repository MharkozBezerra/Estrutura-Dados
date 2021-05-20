#include <stdio.h>
#include <stdlib.h>


int foo(int *x){
	*x = *x+1;
	return *x+1;
}
int main (int argc, char *argv[]){
	int i = 10;
	int j;
	
	j=foo(&i);
	printf("%d",j);
}
