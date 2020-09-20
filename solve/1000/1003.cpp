#include <stdio.h>
int memoc0[100000];
int memoc1[100000];

int fib_countzero(int n){
	int result;
	if(n==0){
		return 1;
	}else if(n==1){
		return 0;
	}else{
		int index=n;
		if(memoc0[index]){
			result=memoc0[index];
		}else{
			result=memoc0[index]=fib_countzero(n-1)+fib_countzero(n-2);
		}
	}
	return result;
}

int fib_countone(int n){
	int result;
	if(n==0){
		return 0;
	}else if(n==1){
		return 1;
	}else{
		int index=n;
		if(memoc1[index]){
			result=memoc1[index];
		}else{
			result=memoc1[index]=fib_countone(n-1)+fib_countone(n-2);
		}
	}
	return result;
}

int main(){
	int N;
	int a;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &a);
		printf("%d %d\n", fib_countzero(a), fib_countone(a));
	}
}