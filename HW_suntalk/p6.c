#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	#endif

	unsigned int num;
	scanf("%u",&num);

	unsigned int table[32];

	printf("Before bits are reversed:\n");
	printf("%u = ",num);
	for(int i = 0; i < 32 ; i++){
		unsigned int tmp = num<<i;
		tmp	 = tmp>>31;
		table[i] = tmp;
		printf("%u",tmp);
		if( (i+1)%8 == 0 )
			printf(" ");
	}
	printf("\n\n");

	num = 0;
	for(int i = 31 ; i >= 0 ; i-- ){
		num = num<<1;
		num += table[i];
	}

	printf("After bits are reversed:\n");
	printf("%u = ",num);
	for(int i = 31; i >= 0 ; i-- ){
		printf("%u",table[i]);
		if( (i-32)%8 == 0 )
			printf(" ");
	}
	printf("\n");

	return 0;
}
