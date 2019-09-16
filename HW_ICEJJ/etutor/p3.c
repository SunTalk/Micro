#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define True 1
#define False 0

int arr[10000];
int size;

int cmp(const void *a, const void *b){

	return *(int *)a - *(int *)b;
}

void _printArray(int arr[], int size){

	printf("%d ", arr[0]);
	for(int i = 1 ; i < size ; i++){

		if(arr[i] == arr[i-1])
			continue;
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

int _getBitNum(int input){

	int cnt = 0;
	while(input > 0){

		input /= 2;
		cnt++;
	}
	return cnt;
}

void _bitExist(int input){

	int allbits = True;
	int existbits = False;
	int len = _getBitNum(input);

	int bit[32] = {0};
	int index = 0;
	for(int i = 0 ; i < 32 ; i++){

		unsigned int a = input;
		a <<= i;
		a >>= 31;

		bit[32-1-i] = a;
		// printf("%d %d\n", i, a);
	}

	for(int i = 0 ; i < size ; i++){

		if(bit[arr[i]] == 0 && allbits){

			allbits = False;
		}
		if(bit[arr[i]] == 1 && !existbits){

			existbits = True;
		}

		if(!allbits && existbits){

			break;
		}
	}
	printf("%s(all bits 1)\n%s(exist bits 1)\n", allbits? "true" : "false", existbits ? "true" : "false");
}

int main(){

	#ifdef DBG
	freopen("1.in", "r", stdin);
	freopen("2.out", "w", stdout);
	#endif

	int n;
	for(int i = 0 ; ; i++){

		scanf("%d", &arr[i]);
		if(arr[i] == -1){
			
			size = i;
			break;
		}
	}
	qsort(arr, size, sizeof(arr[0]), cmp);
	_printArray(arr, size);

	unsigned int a;
	int k = 1;
	while(~scanf("%d", &a)){

		printf("Case %d: %u\n", k++, a);
		_bitExist(a);
	}

	return 0;
}