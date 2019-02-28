//Packages
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Definitions
#define ROW 12
#define COL 6
#define MAX 25

int costMatrix[ROW][COL] =
{
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500},
	{500, 200, 500, 500, 200, 500}
};

//Prototypes
void displayMenu(); //2
int loginMatch(int passcode, int adminPasscode); //4
void initialSeats(char flight[][COL], int count); //1
void printFlightMap(char flight[][COL]); //3
void flightMenu(); //6
int getTotalRevenue(char flight1[][COL], char flight2[][COL], char flight3[][COL]); //5
void seatReservation(char flight[][COL]); //7
void printMessage(char name[], char num[]); //8
void getSafeString(char *string, int maxsize); //WHAT

//Main
int main(void){
	srand(time(NULL));
	int option = 0;
	int passcode = 0;
	int adminPasscode = 105018;
	int count = rand()%20+1;
	int continues = 1;
	int flight = 0;
	char name[20];
	//Flights
	char f1[ROW][COL];
	initialSeats(f1, count);
	char f2[ROW][COL];
	initialSeats(f2, count);
	char f3[ROW][COL];
	initialSeats(f3, count);

	printf("\n********* WELCOME TO MIZZOU AIRLINE BOOKING SYSTEM *********\n\n");
	while(continues == 1){
		displayMenu();
		printf("Choose an option: ");
		scanf("%d", &option);
		while(option != 1 && option != 2 && option != 3){
			printf("\n");
			printf("Wrong option! Choose a right option\n");
			displayMenu();
			printf("Choose an option: ");
			scanf("%d", &option);
		}
		switch(option){
			case 1:
				printf("Enter the login passcode to log in as admin: ");
				scanf("%d", &passcode);
				while(loginMatch(passcode, adminPasscode) == 0){
					printf("Invalid Passcode combination\n\n");
					printf("Enter the login passccode to log in as admin: ");
					scanf("%d", &passcode);
				}

				//printing flight maps
				printf("Printing the Flight Map of flight Columbia to Miami...\n");
				printFlightMap(f1);
				printf("Printing the Flight Map of flight Columbia to Nashville...\n");
				printFlightMap(f2);
				printf("Printing the Flight Map of flight Columbia to Las Vegas...\n");
				printFlightMap(f3);

				printf("The total earnings from all the flights: %d\n", getTotalRevenue(f1, f2, f3));
				printf("You are loggeed out now!\n\n");
				break;
			case 2:
				while(flight != 1 && flight != 2 && flight != 3){
					printf("\n");
					flightMenu();
					printf("Choose a flight: ");
					scanf("%d", &flight);
				}
				printf("Enter your first name: ");
				scanf("%s", name);
				if(flight == 1){
					printFlightMap(f1);
					seatReservation(f1);}
				if(flight == 2){
					printFlightMap(f2);
					seatReservation(f2);}
				if(flight == 3){
					printFlightMap(f3);
					seatReservation(f3);}
				printf("\n");
				break;
			case 3:
				continues = 0;
				break;
		}
	}
	//EXTRA CREDIT CASE
	char *name1 = "Nancy";
	char *flightArray1 = "MIA1050";
	printMessage(name1, flightArray1);

	//END
	return 0;
}

//Functions
void displayMenu(){
	printf("1.)Admin Log-in\n");
	printf("2.)Reserve a seat\n");
	printf("3.)Exit\n");
}

int loginMatch(int passcode, int adminPasscode){
	if(passcode == adminPasscode){
		return 1;
	}
	return 0;
}

void initialSeats(char flight[][COL], int count){
	int row;
	int col;
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j <COL; j++){
			flight[i][j] = 'O';
		}
	}
	for(int z = 0; z < count; z++){
		row = rand()%ROW;
		col = rand()%COL;
		while(flight[row][col] == 'X'){
			row = rand()%ROW;
			col = rand()%COL;
		}
		flight[row][col] = 'X';
	}

}

void printFlightMap(char flight[][COL]){
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			printf("%c ", flight[i][j]);
		}
		printf("\n");
	}
}

void flightMenu(){
	printf("1.)COU---->MIA\n");
	printf("2.)COU---->BNA\n");
	printf("3.)COU---->LAS\n");
}

int getTotalRevenue(char f1[][COL], char f2[][COL], char f3[][COL]){
	int sum = 0;
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(f1[i][j] == 'X'){
				sum += costMatrix[i][j];	
			}
			if(f2[i][j] == 'X'){
				sum += costMatrix[i][j];
			}
			if(f3[i][j] == 'X'){
				sum += costMatrix[i][j];
			}
		}
	}
	return sum;	
}

void seatReservation(char flight[][COL]){
	int seatRow;
	int seatCol;
	printf("Which Seat row do you want?: ");
	scanf("%d", &seatRow);
	while(seatRow < 0 || seatRow > 11){
		printf("Seat rows are between 0 and 11.\n");
		printf("Try Again. Which seat row do you want?: ");
		scanf("%d", &seatRow);
	}
	printf("Which seat column do you want?: ");
	scanf("%d", &seatCol);
	while(seatCol < 0 || seatCol > 5){
		printf("Seat cols are between 0 and 5.\n");
		printf("Try Again. Which seat column do you want?: ");
		scanf("%d", &seatCol);
	}

	//Error Checking
	while(flight[seatRow][seatCol] == 'X'){
		printf("Sorry, this seat is already reserved. Try another\n");
		printf("Which Seat row do you want?: ");
		scanf("%d", &seatRow);
		while(seatRow < 0 || seatRow > 11){
			printf("Seat rows are between 0 and 11.\n");
			printf("Try Again. Which seat row do you want?: ");
			scanf("%d", &seatRow);
		}
		printf("Which seat column do you want?: ");
		scanf("%d", &seatCol);
		while(seatCol < 0 || seatCol > 5){
			printf("Seat cols are between 0 and 5.\n");
			printf("Try Again. Which seat column do you want?: ");
			scanf("%d", &seatCol);
		}
	}

	flight[seatRow][seatCol] = 'X';
	printFlightMap(flight);
	printf("Your requested seat has been reserved\n");
}

void printMessage(char name[], char num[]){
	int i = 0;
	int j = 0;
	char *newString = malloc(sizeof(char)*40);
	char *placeHolderName = "";
	char *placeHolderNum = "";
	while(name[i] != '\0' && num[i] != '\0'){
		//For even numbers
		placeHolderName = "" + name[i] + '\0';
		placeHolderNum = "" + num[i] + '\0';
		if(i % 2 == 0){
			strcat(newString, placeHolderName);//name[i]);
		}
		//For odd numbers
		if(i % 2 == 1){
			strcat(newString, placeHolderNum);//num[i]);
		}
		i++;
	}
	while(name[i] != '\0'){
		placeHolderName = "" + name[i] + '\0';
		strcat(newString, placeHolderName);//name[i]);
		i++;
	}
	while(num[i] != '\0'){
		placeHolderNum = "" + num[i] + '\0';
		strcat(newString, placeHolderNum);//num[i]);
		i++;
	}
	newString += '\0';
	//newString = "Whale";
	printf("%s", newString);
	while(newString[j] != '\0'){
		printf("%c", newString[j]);
		j++;
	}
}
