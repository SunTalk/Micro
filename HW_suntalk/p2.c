#include <stdio.h>
#include <stdlib.h>

int table[40];
void print_hex(){
	
	int hex[10];
	int k = 0;
	for(int i = 0 ; i < 32 ; i+=4 ){
		int tmp = 0;
		for(int j = 0 ; j < 4 ; j++ ){
			tmp += table[i+j]<<j;
		}
		hex[k++] = tmp;
	}

	printf("0x");
	for(int i = 7 ; i >= 0 ; i-- ){
		if( hex[i] > 9 )
			printf("%c",hex[i]+'A'-10);
		else
			printf("%d",hex[i] );
	}
	printf("\n");

}

void print_oct(){

	int oct[15];
	int k = 0;
	for(int i = 0 ; i < 32 ; i+=3 ){
		int tmp = 0;
		for(int j = 0 ; j < 3 ; j++ ){
			tmp += table[i+j]<<j;
		}
		oct[k++] = tmp;
	}
	
	printf("0");
	for(int i = 10 ; i >= 0 ; i-- ){
		printf("%d",oct[i] );
	}
	printf("\n");

}

void print_bin(){
	for(int i = 31 ; i >= 0 ; i--)
		printf("%d",table[i]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("A.in","r",stdin);
	freopen("B.out","w",stdout);
	#endif

	int kase = 1;
	long long num;

	while( ~scanf("%lld",&num) ){

		printf("Case %d: %lld\n",kase++,num);
		for(int i = 0 ; i < 40 ; i++ ){
			long long tmp = (num>>1)<<1;
			table[i] = num - tmp;
			num = num>>1;
		}

		print_bin();
		print_oct();
		print_hex();

	}

	return 0;
}