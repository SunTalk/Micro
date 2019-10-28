#include <stdio.h>
#include <stdlib.h>

void PB(unsigned int k){
	printf("%u = ",k);
	for(int j = 0 ; j < 32 ; j++ ){
		unsigned int tmp = k<<j;
		tmp = tmp>>31;
		printf("%u",tmp);
		if( (j+1)%8 == 0 && j != 31 )
			printf(" ");
	}
	printf("\n");
}

unsigned int ADD(unsigned int a, unsigned int b){
	a = a<<8;
	a += b;
	return a;
}

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	#endif

	unsigned int num;
	char word[4];

	for(int i = 0; i < 4 ; i++)
		scanf("%c ",&word[i]);

	for(int i = 0; i < 4 ; i++){

		printf("%c:\n",word[i]);
		num = (unsigned int)word[i];
		PB(num);

	}

	printf("'%c' and '%c' and '%c' and '%c' packed in an unsigned int:\n",word[0],word[1],word[2],word[3]);
	
	num = 0;
	for(int i = 0 ; i < 4 ; i++ ){
		unsigned int tmp = word[i];
		num = ADD(num,tmp);
	}

	PB(num);

	return 0;
}
