#include<stdio.h>
#include<stdlib.h>

static char HEX[] = "0123456789ABCDEF";

char *decToHex(unsigned int input){

	char *hexed = malloc(sizeof(unsigned int));

	for(int i = 0 ; i < 8 ; i++){

		hexed[i] = '0';
	}
	int index = 7;

	while(input > 0){

		hexed[index--] = HEX[(input & 0xF)];
		input >>= 4;
	}
	return hexed;
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
		char *c = decToHex(input);

		for(int i = 0 ; i < 8 ; i++){

			printf("%c ", c[i]);
		}
		putchar('\n');
	}

	return 0;
}