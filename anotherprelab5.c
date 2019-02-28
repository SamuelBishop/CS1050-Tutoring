//Packages
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definitons
#define arraySize 50

//Prototypes
int check_error(int);
void initialize_array(int [], int);
void print_array(int [], int);

//Main
int main(void){
	int size;
	int array[arraySize];
	printf("Enter an array size: ");
	scanf("%d", &size);
	while(check_error(size) == 0){
		printf("Invalid input enther the size of the input again: ");
		scanf("%d", &size);
	}
	initialize_array(array, size);
	print_array(array, size);
	return 0;
}

//Functions
int check_error(int size){
	if(size < 1 || size > 50){
		return 0;
	}
	return 1;
}

void initialize_array(int array[], int size){
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		array[i] = rand()%10;
	}
}

void print_array(int array[], int size){
	printf("\n");
	for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
// array[5] = {1,2,3,4,5}
// printf("%d", array[0]);
// output: 1
