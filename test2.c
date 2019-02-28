#include <stdio.h>
#include <stdlib.h>

int main (void){
	char * p1[2]= {"Jim", "Reis"};
	char p2[2][5] = {"Jim", "Reis"};
	int size1 = sizeof(p1);
	int size2 = sizeof(p2);
	printf("The size of p1 is %d and the size of p2 is %d\n", size1, size2);
	return 0;
}
