//Packages
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definitions
#define arrayMax 20

//Prototypes
int check_error(int size);
void initialize_2Darray(int array[arrayMax][arrayMax], int size);
void print_2Darray(int array[arrayMax][arrayMax], int size);
int findZeros(int array[][arrayMax], int size);

//Main
int main(void){
	int array[arrayMax][arrayMax];
	int size = 0;
	while(check_error(size) == 0){
		printf("Please enter a value between 1-20 only: ");
		scanf("%d", &size);
	}
	initialize_2Darray(array, size);
	print_2Darray(array, size);
	printf("The number of zeros in 2-D Array: %d\n", findZeros(array, size));
	return 0;
}
//Functions
int check_error(int size){
	if (size >= 1 && size <= 20){
		return 1;
	}
	return 0;
}

void initialize_2Darray(int array[arrayMax][arrayMax], int size){
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			array[i][j] = rand()%10;
		}
	}
}

void print_2Darray(int array[][arrayMax], int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

int findZeros(int array[][arrayMax], int size){
	int numOfZeros = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(array[i][j] == 0){
				numOfZeros++;
			}
		}
	}
	return numOfZeros;
}
