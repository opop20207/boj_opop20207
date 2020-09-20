#include <stdio.h>
unsigned long long T,K,N;

int main(){
	scanf("%llu", &T);
	while(T--){
		scanf("%llu %llu", &K, &N);
		if(K>N/2){
			K=N-K;
		}
		unsigned long long fac2=1,fac=1;
		for(unsigned long long i=K;i>=1;i--){
			fac*=i;
		}
		for(unsigned long long i=N;i>=N-K+1;i--){
			fac2*=i;
		}
		printf("%llu\n",fac2/fac);
	}
}