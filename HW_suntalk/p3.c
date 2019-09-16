#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[40];
int check[40];

int all(){
	for(int i = 0; i < 40 ; i++ )
		if( check[i] && !table[i] )
			return 0;
	return 1;
}
int exist(){
	for(int i = 0; i < 40 ; i++ )
		if( check[i] && table[i] )
			return 1;
	return 0;	
}

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	#endif


	int kase = 1;
	long long num;
	memset(check,0,sizeof(check));

	while( ~scanf("%lld",&num) && num != -1 )
		check[num] = 1;

	for(int i = 0 ; i < 40 ; i++ )
		if( check[i] == 1 )
			printf("%d ",i);
	printf("\n");

	while( ~scanf("%lld",&num) ){

		printf("Case %d: %lld\n",kase++,num);
		for(int i = 0 ; i < 40 ; i++ ){
			long long tmp = (num>>1)<<1;
			table[i] = num - tmp;
			num = num>>1;
		}

		if( all() )
			printf("true");
		else
			printf("false");
		printf("(all bits 1)\n");

		if( exist() )
			printf("true");
		else
			printf("false");
		printf("(exist bits 1)\n");

	}

	return 0;
}