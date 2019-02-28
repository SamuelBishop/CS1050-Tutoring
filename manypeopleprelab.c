//Packages
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definition
int sizeArray = 50;

//Prototypes
int check_error(int);
void initialize_array(int [], int);
void print_array(int[], int);

//Main
int main(void){
	int size = 0;
	int array [sizeArray];
	printf("Enter the size of the input: ");
	scanf("%d", &size);
	check_error(size);
	initialize_array(array,size);
	print_array(array,size);
	return 0;
}

//Functions
int check_error(int size){
	while (size < 1 || size > 50){
		printf("Invalid input enter the size of the input again: ");
		scanf("%d", &size);
	}
	return size;
}

void initialize_array(int array[], int size){
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		array[i] = rand()%10;
	}
}

void print_array(int array[], int size){
	printf("Input array 1");
	printf("\n");
	for(int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
