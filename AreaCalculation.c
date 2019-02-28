//Packages
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definitons
#define PI 3.14159

//Main
int main (void){
	//Setup and getting square/cube/circle responce
	int a = 0;
	int value = -1;
	while (a != 1 && a != 2 && a != 3)
	{
		if( a != 0 && a != 1 && a != 2 && a != 3)
		{
			printf("That was not a correct number, please enter a proper number\n");
		}
		printf("Would you like to calculate the area of a\n 1)Square\n 2)Cube\n 3)Circle\n");
		scanf("%d", &a);
	}

	//Square
	if(a == 1){
		while (value < 0)
		{
			if(value < 0 && value != -1)
			{
				printf("You entered either 0 or a negative number, try again\n");
			}
			printf("Enter a positive number\n");
			scanf("%d", &value);
			printf("The area of the square is %d\n", value*value);
		}
	}

	//Sphere
	if(a == 2){
		while (value < 0)
		{
			if(value < 0 && value != -1)
			{
				printf("You entered either 0 or a negative number, try again\n");
			}
			printf("Enter a positive number\n");
			scanf("%d", &value);
			printf("The area of the cube is %d\n", value*value*value);
		}
	}

	if(a == 3){
		while (value < 0)
		{
			if(value < 0 && value != -1)
			{
				printf("You entered either 0 or a negative number, try again\n");
			}
			printf("Enter a positive number\n");
			scanf("%d", &value);
			printf("The area of the circle is %f\n", PI*value*value);
		}
	}

	//Ends main
	return 0;
}
