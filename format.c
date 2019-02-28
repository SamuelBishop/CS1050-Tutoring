//Packages
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//Definitions
#define height 72

//Function Prototypes
void printHeight(int tallness);
void whatIsMyName(char name[]);

//Main
int main(void){
	int number;
	char name[30];
	printf("Enter your height: ");
	scanf("%d", &number);
	printHeight(number);
	printf("Enter your name here: ");
	scanf("%s", name);
	whatIsMyName(name);
	return 0;
}

//Function Declaration
void printHeight(int tallness){
	printf("%d\n", tallness);
}

void whatIsMyName(char name[]){
	printf("Your name is %s\n", name);
}
