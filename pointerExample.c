#include <stdio.h>
#include <stdlib.h>

int main(void){
	int size;
	printf("Enter an array size: ");
	scanf("%d", &size);

	int *p = malloc(sizeof(int) * size);
	for(int i = 0; i < size; i++){
		*(p + i) = i;
		printf("%d ", *(p + i));
	}
	return 0;
}
