#include <stdio.h>
#include <stdlib.h>

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

		printf("%c:\n%u = ",word[i], word[i]);
		num = (unsigned int)word[i];
		// printf("%u\n",num);
		for(int j = 0 ; j < 32 ; j++ ){
			unsigned int tmp = num<<j;
			tmp = tmp>>31;
			printf("%u",tmp);
			if( (j+1)%8 == 0 && j != 31 )
				printf(" ");
		}
		printf("\n");

	}

	printf("'%c' and '%c' and '%c' and '%c' packed in an unsigned int:\n",word[0],word[1],word[2],word[3]);
	num = 0;
	for(int i = 0 ; i < 4 ; i++ ){
		unsigned int tmp = word[i];
		tmp = tmp<<((3-i)*8);
		num += tmp;
	}
	printf("%u = ",num);
	for(int j = 0 ; j < 32 ; j++ ){
		unsigned int tmp = num<<j;
		tmp = tmp>>31;
		printf("%u",tmp);
		if( (j+1)%8 == 0 && j != 31 )
			printf(" ");
	}
	printf("\n");

	return 0;
}