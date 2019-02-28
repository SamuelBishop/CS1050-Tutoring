//Packages
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Prototypes
void displayMenu();
int errorCheck(int);
int errorCheckUnits(int);
float getRate(int, int);
int charge(int);

//Main
int main(void){
	displayMenu();
	return 0;
}

//displayMenu
void displayMenu(){
	printf("\n1.Residential\n2.Commercial\n3.Industrial\n");
}
