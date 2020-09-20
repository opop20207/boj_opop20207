#include <stdio.h>
int func(int temp){
	long long n, min, max, powN, count=0;
	for(n=1;;n++){
		powN=n*n;
		min=powN-n+1;
		max=powN+n;
		if(min<=temp && temp<=max){
			if(min<=temp && temp<=powN) count=n*2-1;
			else count=n*2;
			break;
		}
	}
	return count;
}

int main(){
	int T;
	int x,y,temp;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &x, &y);
		temp=y-x;
		printf("%d\n",func(temp));
	}
}