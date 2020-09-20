#include <stdio.h>

int main(){
	int a;
	int N, q,w;
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		scanf("%d %d", &q,&w);
		a=1;
		for(int j=0;j<w;j++){
			a*=q;
			a=a%10;
		}
		if(a==0){
			a=10;
		}
		printf("%d\n",a);
	}
}