#include <stdio.h>

int main(void){
	int array[50];
	int size = 50;
	for(int i = 0; i < size; i++){
		array[i] = i;
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
