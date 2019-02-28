//Packages
#include <stdio.h>

//Prototypes
int courseNumCheck(int);
float getScore(void);
float getScorePoint(float, int);
void printComment(float);

//Main
int main(void){
	int courseNumber;
	int count = 1;
	float score = 0;
	float sum = 0;
	float ASP;
	printf("\n==============================\n");
	printf("STUDENT ASP CALCULATOR\n");
	printf("==============================\n");
	printf("Enter the number of courses: ");
	scanf("%d", &courseNumber);
	while (courseNumCheck(courseNumber) != 1){
		printf("Error! Please enter a Number of Courses greater than 1: ");
		scanf("%d", &courseNumber);
	}
	while(count < courseNumber + 1){
		printf("Enter the Student Score for Course %d (Percent) : ", count);
		score = getScore();
		printf("Point = %.2f\n", score);
		sum += score;
		count++;
	}
	ASP = getScorePoint(sum, courseNumber);
	printf("\nThe Student ASP: %.2f\n", ASP);
	printf("==============================\n");
	printComment(ASP);
	printf("==============================\n");
	return 0;
}

//Functions
int courseNumCheck(int variable){
	if(variable > 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Get Score Function
float getScore(void){
	float score = 0;
	scanf("%f", &score);
	if(score >= 95)
	{
		return 4;
	}
	if(score >= 90 && score <= 94)
	{
		return 3.5;
	}
	if(score >= 85 && score <= 89){
		return 3;
	}
	if(score >= 80 && score <= 84){
		return 2.5;
	}
	if(score >= 75 && score < 79){
		return 2;
	}
	if(score > 70 && score < 74){
		return 1;
	}
	return 0;
}

float getScorePoint(float totalPoints, int classesTaken){
	float ASP;
	ASP = totalPoints/classesTaken;
	return ASP;
}

void printComment(float ASP){
	if(ASP >= 3.8 && ASP <= 4.0){
		printf("Excellent\n");
	}
	if(ASP >= 3.5 && ASP <= 3.7){
		printf("Very Good\n");
	}
	if(ASP >= 3.0 && ASP <= 3.49){
		printf("Good\n");
	}
	if(ASP >= 2.5 && ASP <= 2.99){
		printf("Satisfactory\n");
	}
	if(ASP >= 2.0 && ASP <= 2.49){
		printf("Not passed\n");
	}
	if(ASP >= 0 && ASP <= 1.99){
		printf("Unofficial drop\n");
	}
}
