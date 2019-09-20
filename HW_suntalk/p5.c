#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	#endif

	unsigned int num;
	scanf("%u",&num);

	printf("The packed character representation is:\n%u = ",num);
	for(int i = 0; i < 32 ; i++){
		unsigned int tmp = num<<i;
		tmp = tmp>>31;
		printf("%u",tmp);
		if( (i+1)%8 == 0 )
			printf(" ");
	}
	printf("\n\n");
	unsigned int word[4];
	word[0] = num>>24;
	word[1] = (num<<8)>>24;
	word[2] = (num<<16)>>24;
	word[3] = (num<<24)>>24;

	// word[0] = word[1] = word[2] = word[3] = 50;
	// printf("The unpacked character are '%c' and '%c' and '%c' and '%c'\n",word[0] ,word[1] ,word[2] ,word[3]);
	for(int i = 0 ; i < 4 ; i++ ){
		printf("%u = ",word[i]);

		for(int j = 0 ; j < 32 ; j++ ){
			unsigned int tmp = word[i]<<j;
			tmp = tmp>>31;
			printf("%u",tmp);
			if( (j+1)%8 == 0 )
				printf(" ");
		}
		printf("\n");

	}


	return 0;
}
