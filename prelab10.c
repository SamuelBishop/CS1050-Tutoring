#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Definitions
#define MAX 50

//Prototypes
int getString(char *string);
int errorCheck(int size);
int checkString(char *string, int size);

//Main
int main(void){
	/*int initSize = NULL;
	printf("Enter the size of the string: "); 
	scanf("%d", &initSize);
	while(errorCheck(initSize) == 0){
		printf("Please enter again: ");
		scanf("%d", &initSize);
	}*/
	char *string = malloc(sizeof(char) * MAX);
	//Above is the same thing as char string[MAX];
	int size = getString(string);
	printf("You entered: %s which is size of %d\n", string, size);
	return 0;
}

int errorCheck(int size){
	if(size >= 1 && size <= 20){
		return 1;
	}
	return 0;
}

int checkString(char *string, int size){
	int ret = 1;
	for(int i = 0; i < size; i++){
		if(*(string + i) < 65 || ((*(string + i) > 90 && *(string + i) < 97)) || *(string + i) > 122){
			ret = 0;
		}
	}

	return ret;
}

int getString(char *string){
	int initSize;
	printf("Enter the size of the string: ");
	scanf("%d", &initSize);
	while(errorCheck(initSize) == 0){
		printf("Please enter again: ");
		scanf("%d", &initSize);
	}
	//string = malloc(sizeof(char) * initSize);
	printf("\nPlease enter the string: ");
	scanf("%s", string);
	while(strlen(string) > initSize){
			printf("The string entered is longer than allowed here\n");
			printf("Please enter a valid string: ");
			scanf("%s", string);
	}

	while(checkString(string, strlen(string)) == 0){
		printf("Please enter a valid string: ");
		scanf("%s", string);
	}

	for(int j = 0; j < strlen(string); j++){
		*(string + j) = toupper(*(string + j));
	}

	return strlen(string);
}
