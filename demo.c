#include <stdio.h>
#include <stdlib.h>

void math(int);
void correctMath(int*);

int main(void){
	
	//For just int
	int something = 0;
	scanf("%d", &something);
	math(something);
	printf("The value of something is: %d\n", something);

	//For int pointer
	int *somethingnumba2 = malloc(sizeof(int));
	scanf("%d", somethingnumba2);
	correctMath(somethingnumba2);
	printf("\nThe value of somethingnumba2 is: %d\n", *somethingnumba2);
	return 0;
}

void math(int number){
	number += 5;
}

void correctMath(int *number){
	*(number) += 5;
}

