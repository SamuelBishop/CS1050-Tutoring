//Packages
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definitions

//Prototypes
void displayMenu();
int errorCheck(int option);
int errorCheckUnits(int units);
float getRate(int units, int option);
int charge(int option);

//Main
int main(void){
	int option;
	int units;
	float connectionCharge = 0;
	float rate;
	int continues = 1;
	int count = 0;
	float sum = 0;
	printf("***** ELECTRICTITY BILL CALCULATOR *****\n");
	while(continues == 1){
		displayMenu();
		option = errorCheck(0);
		connectionCharge = charge(option);
		printf("Enter the number of units (in kWh): ");
		scanf("%d", &units);
		while(errorCheckUnits(units) == 0){
			printf("Invalid input!\n");
			printf("Enter the number of units (in kWh): ");
			scanf("%d", &units);
		}
		rate = getRate(units, option);
		printf("Total energy charge for the customer is: $\t %.2f\n", units*rate);
		printf("Connection charge for this customer is: $\t %.2f\n", connectionCharge);
		printf("Total bill due from this connection is: $\t %.2f\n", (units*rate) + connectionCharge);
		printf("Do you want to continue and calculate another bill? If Yes enter 1, else 0: ");
		scanf("%d", &continues);
		sum += (units*rate) + connectionCharge;
		count++;
	}
	printf("\nYou calculated the bill %d times and the total amount from all of the bills due is %.2f\n", count, sum);
	return 0;
}

//displayMenu
void displayMenu()
{
	printf("\n1. Residential\n2. Commercial\n3. Industrial\n\n");
}

//errorCheck
int errorCheck(int option)
{
	printf("Choose the type of connection: ");
	scanf("%d", &option);
	while(option != 1 && option != 2 && option != 3){
		printf("Invalid Choice! Please enter a valid choice\n\n");
		displayMenu();
		printf("Choose the type of connection: ");
		scanf("%d", &option);
	}
	return option;
}

//errorCheckUnits
int errorCheckUnits(int units){
	if (units < 0){
		return 0;
	}
	else{
		return 1;
	}
}

//getRate
float getRate(int units, int option){
	float rate;
	switch(option){
		case 1:
			if(units >= 0 && units <= 200){
			rate = .075;}
			if(units > 200 && units <= 700){
			rate = .10;}
			if(units > 700 && units <= 1250){
			rate = .135;}
			if(units >= 1250){
			rate = .15;}
			break;
		case 2:
			if(units >= 0 && units <= 300){
			rate = .105;}
			if(units > 300 && units <= 1000){
			rate = .14;}
			if(units > 1000 && units <= 2000){
			rate = .175;}
			if(units >= 2000){
			rate = .20;}
			break;
		case 3:
			if(units >= 0 && units <= 500){
			rate = .365;}
			if(units > 500 && units <= 2000){
			rate = .40;}
			if(units > 2000 && units <= 3000){
			rate = .455;}
			if(units >= 3000){
			rate = .50;}
			break;
	}
	return rate;
}

//charge
int charge(int option){
	int connectionCharge = 0;
	if(option == 1){
		connectionCharge = 25;
	}
	if(option == 2){
		connectionCharge = 90;
	}
	if(option == 3){
		connectionCharge = 850;
	}
	return connectionCharge;
}


