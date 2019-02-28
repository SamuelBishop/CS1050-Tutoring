//Packages
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definitons

//Prototypes
int errorCheck(int number);
void factorial(int *output, int limit);
void printArray(int *input, int size);

//Main
int main(void){
	int size;
	int *array;
	printf("Enter a value to calculate the factorial: ");
	scanf("%d", &size);
	while(errorCheck(size) == 0){
		printf("Input must be larger than 0 and less than 10. Please enter again: ");
		scanf("%d", &size);
	}
	array = malloc(sizeof(int)*size);
	factorial(array, size);
	printArray(array, size);
	return 0;
}

//Functions
int errorCheck(int number){
	if(number >= 0 && number <= 10){
		return 1;
	}
	return 0;
}

void printArray(int *input, int size){
	printf("\n");
	for(int i = 0; i < size; i++){
		printf("%d ", *(input + i)); //input[i]
	}
	printf("\n");
}

void factorial(int *output, int limit){
	int temp;
	*(output) = 1;
	for(int i = 1; i < limit; i++){
		temp = i + 1;
		*(output + i) += *(output + (i - 1)) * (temp);
	}
}
