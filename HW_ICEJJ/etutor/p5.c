#include<stdio.h>
#include<stdlib.h>

#define uint unsigned int

uint c[] = {0xFF000000, 0xFF0000, 0xFF00, 0xFF};

void printBinary(uint input){

	for (int i = 0; i < 32; i++){


		uint a = input;
		a <<= i;
		a >>= 31;

		printf("%d", a);
		if((i+1) % 8 == 0){

			putchar(' ');
		}

	}
	putchar('\n');
}

int unpacked(uint input){

	int arr[4];
	int index = 0;
	for(int i = 0 ; i < 32 ; i += 8){

		uint a = input;
		a <<= i;
		a >>= 24;

		arr[index++] = a;
	}

	for(int i = 0 ; i < 4 ; i++){

		printf("%d = ", arr[i]);
		printBinary(arr[i]);
	}
}

int main(){

	#ifdef DBG
	freopen("1.in", "r", stdin);
	freopen("2.out", "w", stdout);
	#endif

	uint input;

	while(~scanf("%u", &input)){

		// printf("test");
		printf("The packed character representation is:\n%u = ", input);
		printBinary(input);
		putchar('\n');
		unpacked(input);
	}

	return 0;
}