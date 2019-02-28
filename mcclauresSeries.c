#include <stdio.h>
#include <math.h>

//Prototypes
int factorial(int input);
int mcClauren(int input);

int main(void){
	int number;
	int numberFactorial;
	printf("What number do you want to make factorial?: ");
	scanf("%d", &number);
	numberFactorial = factorial(number);
	printf("%d factorial is: %d\n", number, numberFactorial);
	printf("\n%.5f\n", (float)((float)10/(float)numberFactorial)); 
	return 0;
}

int factorial(int input){
	int factorial = 1;
	int temp;
	for(int i = 0; i < input; i++){
		temp = i + 1;
		factorial += factorial * temp;
	}
	return factorial;
}

int mcClauren(int x){
	return 0;
}
