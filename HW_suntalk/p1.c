#include <stdio.h>
#include <stdlib.h>

int table[40];
void print_hex(){
	
	int ans[10];
	int k = 0;
	for(int i = 0 ; i < 32 ; i+=4 ){
		int tmp = 0;
		for(int j = 0 ; j < 4 ; j++ ){
			tmp += table[i+j]<<j;
		}
		ans[k++] = tmp;
	}

	for(int i = 7 ; i >= 0 ; i-- ){
		if( ans[i] > 9 )
			printf("%c ",ans[i]+'A'-10);
		else
			printf("%d ",ans[i] );
	}
	
	printf("\n");

}

int main(int argc, char const *argv[])
{
	
	#ifdef DBG
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
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

		print_hex();

	}

	return 0;
}