#include<stdio.h>
#include<stdlib.h>

#define uint unsigned int

void printBinary(uint input){

	for (int i = 0; i < 32; i++){

		uint a = input;
		a <<= i;
		a >>= 31;

		printf("%d", a);
		if(i+1 % 8 == 0){
			putchar(' ');
		}
	}
	putchar('\n');
}

uint packCharacter(uint a, uint b){

	
}

int main(){

	#ifdef DBG
	freopen("1.in", "r", stdin);
	freopen("2.out", "w", stdout);
	#endif // DBG

	char a, b, c, d;
	while(~scanf("%d%d%d%d", &a, &b, &c, &d)){

		printf("%c:\n%d = ", a, a);
		print_binary(a);

		printf("%c:\n%d = ", b, b);
		print_binary(b);

		printf("%c:\n%d = ", c, c);
		print_binary(c);

		printf("%c:\n%d = ", d, d);
		print_binary(d);
	}

	return 0;
}