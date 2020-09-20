#include <stdio.h>
#define INF 987654321
int N, M;
int six[51];
int one[51];
int res = INF;

int min(int a, int b) {
	return a < b ? a : b;
}

int find(int now, int price) {
	if (now == 0) {
		return price;
	}
	if (now >= 6) {
		int buy = INF;
		for (int i = 0; i < M; i++) {
			buy = min(buy, min(six[i], one[i] * 6));
		}
		find(now - 6, price + buy);
	}
	else {
		int buy = INF;
		for (int i = 0; i < M; i++) {
			buy = min(buy, min(six[i], one[i] * now));
		}
		find(0, price + buy);
	}

}

int main() {
	scanf("%d %d", &N, &M);
	int minsix=INF, minone=INF;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &six[i], &one[i]);
		minsix = min(minsix, six[i]);
		minone = min(minone, one[i]);
	}
	if (N < 6) {
		int temp1 = minsix;
		int temp2 = minone * N;
		printf("%d\n", min(temp1, temp2));
	}
	else {
		if (minsix < minone * 6) {
			int temp1 = (N / 6) * minsix + (N % 6) * minone;
			int temp2 = (N / 6 + 1) * minsix;
			printf("%d\n", min(temp1, temp2));
		}
		else {
			printf("%d\n", minone * N);
		}
	}
}