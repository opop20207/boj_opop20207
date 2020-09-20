#include <stdio.h>
int N, M, count;
int arr[100];
int out[100];

void left() {
	int newarr[100];
	for (int i = 0; i < N; i++) {
		newarr[i] = arr[(i + 1) % N];
	}
	for (int i = 0; i < N; i++) {
		arr[i] = newarr[i];
	}
}

void right() {
	int newarr[100];
	for (int i = 0; i < N; i++) {
		newarr[(i + 1) % N] = arr[i];
	}
	for (int i = 0; i < N; i++) {
		arr[i] = newarr[i];
	}
}

void DeQ() {
	left();
	N--;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &out[i]);
	}
	int now, o;
	now = arr[0];
	for (int i = 0; i < M; i++) {
		for (o = 0; arr[o] != out[i]; o++);
		if (o > N / 2) {
			while (now != out[i]) {
				right();
				count++;
				now = arr[0];
			}
		}
		else {
			while (now != out[i]) {
				left();
				count++;
				now = arr[0];
			}
		}
		DeQ();
		now = arr[0];

	}
	printf("%d", count);
}