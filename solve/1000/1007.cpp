#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int T, N;
P arr[21];
bool visit[21];
double res;

void DFS(int depth, int num) {
	if (depth == 0) {
		pair<long long, long long> sum1 = { 0,0 };
		pair<long long, long long> sum2 = { 0,0 };
		for (int i = 0; i < N; i++) {
			if (visit[i]) {
				sum1.first += arr[i].first;
				sum1.second += arr[i].second;
			}
			else {
				sum2.first -= arr[i].first;
				sum2.second -= arr[i].second;
			}
		}
		long long t1, t2;
		t1 = sum1.first + sum2.first;
		t2 = sum1.second + sum2.second;
		double temp = sqrtl(t1 * t1 + t2 * t2);
		res = min(res, temp);
		return;
	}

	for (int i = num; i < N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			DFS(depth - 1, i+1);
			visit[i] = false;
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		res = 3000000;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &arr[i].first, &arr[i].second);
		}
		DFS(N / 2, 0);
		printf("%.10lf\n", res);
	}
}