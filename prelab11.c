//Packages
#include <stdio.h>
#include <stdlib.h> //Only used for exit(0)
#include <string.h>

//Definitons
#define MAX 30

//Structs
typedef struct{
	char name[20];
	int grade;
	int id;
}student;

//Prototypes
void get_size(int *ptr);
int check_size(int number);
void load_sructdata(char *filename, int size);
void print_data(int size);

//Global Variables
student Info[MAX]; //Creating an array of students size 30

//Main
int main (int numargs, char **filename){ //int argc counts how many arguments we have, char **argv are the names of the args
	/*EXAMPLE:
 	./a.out prelab_data.txt
	^ arg1	^ arg2
	MEANING: numargs = 2
	MEANING: filename[0] = ./a.out, filename[1] = prelab_data.txt
	*/
	int size;
	if(numargs != 2){
		printf("Insufficient arguments! Load the correct number of input arguments!\n");
		exit(0);
	}
	get_size(&size);
	load_sructdata(filename[1], size);
	print_data(size);
	return 0;
}

//Functions
void get_size(int *ptr){
	printf("Enter the size of the Input: ");
	scanf("%d", ptr);
	printf("=======================================\n");
	while(check_size(*ptr)){
		printf("Invalid Size Entered! Minimum is 1 and Maximum is 22!\n");
		printf("======================================\n");
		printf("Please enter again: ");
		scanf("%d", ptr);
		printf("======================================\n");
	}
}

int check_size(int number){
	if(number < 1 || number > 22){
		return 1;
	}
	return 0;
}

void load_sructdata(char *filename, int size){
	int i = 0;
	FILE *fptr; //Creating the file pointer
	fptr = fopen(filename, "r"); //Setting the file pointer equal to the filename you entered
	if(fptr == NULL){ //Checking if that file actually exists
		printf("Cannot open file \n");
		exit(0);
	}
	while(fscanf(fptr, "%s %d %d", Info[i].name, &Info[i].id, &Info[i].grade) != EOF){ //Saying: While there is text in this file, put the values in the correct element of the info struct
		i++;
	}
	fclose(fptr); //Closing the file (This is important)
}

void print_data(int size){
	printf("Student-Record\n\ns/no\tName\t\tId\tGrade\n");
	for(int j = 0; j < size; j++){
		if(strlen(Info[j].name) < 8){ //Just a fix for an error I encountered where if someone's name is longer than 7 chars the code won't indent correctly
			printf("%d\t%s\t\t%d\t%d\n", j + 1, Info[j].name, Info[j].id, Info[j].grade);
		}
		else{
			printf("%d\t%s\t%d\t%d\n", j + 1, Info[j].name, Info[j].id, Info[j].grade);
		}
	}
}
