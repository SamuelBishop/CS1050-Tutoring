//Packages
#include <stdio.h>

//Definitons

//Prototypes
void displayMenu();
int errorCheck(int option);
int errorCheckUnits(int units);
float getRate(int units, int option);
float charge(int option);

//Main
int main(void){
	displayMenu();
	int option = errorCheck(0);
	printf("%d\n", option);
	return 0;
}

//Functions
void displayMenu(){
	printf("\n1)Residential\n2.Commercial\n3)Industrial\n");
}

int errorCheck(int option){
	printf("\nChoose the type of connection: ");
	scanf("%d", &option);
	while(option != 1 && option != 2 && option != 3){
		printf("Invalid integer, please enter 1, 2, or 3: ");
		scanf("%d", &option);
	}
	return option;
}
