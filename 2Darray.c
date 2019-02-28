//Packages
#include <stdio.h>

#define size 20

int main(void){
	int array[size][size];
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			array[i][j] = 2;
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
