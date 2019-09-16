#include<stdio.h>
#include<stdlib.h>

static char ch[] = "0123456789ABCDEF";

void printBinary(unsigned int input){

	for(int i = 0 ; i < 32 ; i++){

		unsigned int a = input;
		a <<= i;
		a >>= 31;

		printf("%c", ch[(a & 0b1)]);
	}
	putchar('\n');
}

void printOctal(unsigned int input){

	unsigned int f = input >> 30;
	printf("0%c", ch[(f & 07)]);

	for(int i = 2 ; i < 32 ; i += 3){

		unsigned int a = input;
		a <<= i;
		a >>= 29;

		printf("%c", ch[(a & 07)]);
	}
	putchar('\n');
}

void printHex(unsigned int input){

	printf("0x");
	for(int i = 0 ; i < 8; i++){

		unsigned int a = input;
		a <<= i*4;
		a >>= 28;
		printf("%c", ch[(a & 0xF)]);
	}
	putchar('\n');
}

int main(){

	#ifdef DBG
	freopen("1.in", "r", stdin);
	freopen("2.out", "w", stdout);
	#endif

	unsigned int input;
	int k = 1;

	while(~scanf("%u", &input)){

		printf("Case %d: %u\n", k++, input);
		printBinary(input);
		printOctal(input);
		printHex(input);
	}

	return 0;
}