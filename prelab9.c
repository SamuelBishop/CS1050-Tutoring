//Packages
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//Definitons
#define MAX 50

//Functions
int size;
void get_size(int *pointer);
int check_size(int size);
void initialize_pointerArray(int * pointer, int size);
void print_pointerArray(int * pointer, int size);
int find_max(int *pointer, int size);

int main(void){
	int array[MAX];
	int *pointer = array;
	int size;
	get_size(&size);
	initialize_pointerArray(pointer, size);
	printf("\nInput array\n");
	print_pointerArray(pointer, size);
	printf("\nThe largest value in the pointer is: %d\n", find_max(pointer, size));
	return 0;
}

int check_size(int size){
	if(size >= 1 && size <= 50){
		return 1;
	}
	return 0;
}

void get_size(int *pointer){
	int size;
	printf("Enter the size of the input: ");
	scanf("%d", &size);
	while(check_size(size) == 0){
		printf("Invalid input enter the size of the array again: ");
		scanf("%d", &size);
	}
	*pointer = size;
}

void initialize_pointerArray(int *pointer, int size){
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		*(pointer + i) = rand()%10 + 1;
	}
}

void print_pointerArray(int *pointer, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", *(pointer + i));
	}
}

int find_max(int *pointer, int size){
	int max = 0;
	for(int i = 0; i < size; i++){
		if(*(pointer + i) > max){
			max = *(pointer + i);
		}
	}
	return max;
}
