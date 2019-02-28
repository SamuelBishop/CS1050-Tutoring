//Packages 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definitions

//Prototypes
int get_record_count(char *filename);
int load_data(char *filename, int *accountNums, float *accountBalances, int size);
void print_data(int *accountNums, float *accountBalances, int size);
int highest_amount(float *floats, int size);
int lowest_amount(float *floats, int size);
float average_amount(float *floats, int size);
int write_data(char *outputFile, int *accNumInfo, float *accInfo, int numAccs, int indexHighest, int indexLowest, float average);

//Main
int main(int argc, char **argv){
	//Variables before starting main
	int indexOfHighest;
	int indexOfLowest;
	float averageMonies;
	
	printf("\n");
	if(argc != 3){
		printf("Incorrect number of arguments\n");
		printf("Syntax: ./a.out input_file_name output_file_name\n");
		exit(0);
	}
	int size = get_record_count(argv[1]);
	printf("%d records in the file.\n", size);
	int *accountNums = malloc(sizeof(int) * size);
	float *accountBalances = malloc(sizeof(float) * size);
	if(load_data(argv[1], accountNums, accountBalances, size)){
		print_data(accountNums, accountBalances, size);
	}
	printf("\n");
	indexOfHighest = highest_amount(accountBalances, size);
	indexOfLowest = lowest_amount(accountBalances, size);
	averageMonies = average_amount(accountBalances, size);
	printf("The highest amount of %.2f in the account number %d\n", accountBalances[indexOfHighest], accountNums[indexOfHighest]);
	printf("The lowest amount of %.2f in the account number %d\n", accountBalances[indexOfLowest], accountNums[indexOfLowest]);
	printf("The average amount of %.2f\n", averageMonies);
	write_data(argv[2], accountNums, accountBalances, size, indexOfHighest, indexOfLowest, averageMonies);
}

int get_record_count(char *filename){
	int size = 0;
	char ch;
	FILE *fptr;
	fptr = fopen(filename, "r");
	if(fptr == NULL){
		printf("Unable to open the input file\n");
		exit(0);
	}
	while((ch = fgetc(fptr)) != EOF){
		if(ch == '\n'){
			size++;
		}
	}
	fclose(fptr);
	return size;
}

int load_data(char *filename, int *accountNums, float *accountBalances, int size){
	int i = 0;
	FILE *fptr;
	fptr = fopen(filename, "r");
	if(fptr == NULL){
		return 0;
	}
	while(fscanf(fptr, "%d %f", &accountNums[i], &accountBalances[i])!=EOF){
		i++;
	}
	fclose(fptr);
	return 1;
}

void print_data(int *accountNums, float *accountBalances, int size){
	printf("Account No.\tAmount\n");
	for(int i = 0; i < size; i++){
		printf("%d\t\t%.2f\n", accountNums[i], accountBalances[i]);
	}
}

int highest_amount(float *accountBalances, int size){
	float max = 0;
	int indexOfMax;
	for(int i = 0; i < size; i++){
		if(accountBalances[i] > max){
			max = accountBalances[i];
			indexOfMax = i;
		}
	}
	return indexOfMax;
}

int lowest_amount(float *accountBalances, int size){
	float min = 100000000;
	int indexOfMin;
	for(int i = 0; i < size; i++){
		if(accountBalances[i] < min){
			min = accountBalances[i];
			indexOfMin = i;
		}
	}
	return indexOfMin;
}

float average_amount(float *accountBalances, int size){
	float totalMonies = 0;
	for(int i = 0; i < size; i++){
		totalMonies += accountBalances[i];
	}
	float average = totalMonies/((float)size);
	return average;
}

int write_data(char *filename, int *accountNums, float *accountBalances, int size, int indexHighest, int indexLowest, float average){
	FILE *outputFile;
	if((outputFile = fopen(filename, "w")) == NULL)
	{
		printf("Output file not opened\n");
		return 0;
	}
	fprintf(outputFile, "Account Number\tAccount Balance\n");
	for(int i = 0; i < size; i++){
		fprintf(outputFile, "%d\t%.2f\n", accountNums[i], accountBalances[i]);
	}
	fprintf(outputFile, "\n");
	fprintf(outputFile, "The highest amount of %.2f in the account number %d\n", accountBalances[indexHighest], accountNums[indexHighest]);
	fprintf(outputFile, "The lowest amount of %.2f in the account number %d\n", accountBalances[indexLowest], accountNums[indexLowest]);		fprintf(outputFile, "The average amount of %.2f\n", average);
	return 1;
}
