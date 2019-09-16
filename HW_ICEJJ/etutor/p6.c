#include<stdio.h>
#include<stdlib.h>

#define uint unsigned int

void printBinary(uint input){

	for(int i = 0 ; i < 32 ; i++){

		uint a = input;
		a <<= i;
		a >>= 31;

		printf("%d", a);
		if((i+1)%8 == 0)
			putchar(' ');
	}
	putchar('\n');
}

uint reverseBits(uint input){

	uint cnt = sizeof(input)*8 - 1;
	uint rev = input;

	input >>= 1;
	while(input){

		rev <<= 1;
		rev |= input&1;
		input >>= 1;
		cnt--;
	}
	rev <<= cnt;
	return rev;
}


int main(){

	#ifdef DBG
	freopen("1.in", "r", stdin);
	freopen("2.out", "w", stdout);
	#endif

	uint n;
	while(~scanf("%d", &n)){

		printf("Before bits are reversed:\n%u = ", n);
		printBinary(n);
		putchar('\n');
		uint s = reverseBits(n);
		printf("After bits are reversed:\n%u = ", s);
		printBinary(s);
	}
	return 0;
}