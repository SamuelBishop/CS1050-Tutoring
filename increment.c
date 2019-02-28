#include <stdio.h>

int main (void){
	int size1;
	int size2;
	int size3;
	int size4;
	//To show item++
	for(size1 = 0; size1 < 10; size1++){
		printf("%d ", size1);
	}
	printf("\n\n");
	//To show ++item
	for(size2 = 0; size2 < 10; ++size2){
		printf("%d ", size2);
	}
	printf("\n\n");
	//To show item--
	for(size3 = 10; size3 > 0; size3--){
		printf("%d ", size3);
	}
	printf("\n\n");
	//To show --item
	for(size4 = 10; size4 > 0; --size4){
		printf("%d ", size4);
	}
	return 0;
} 
