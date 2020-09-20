#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<int> q;
vector<int> v[1010];

int res[1010];
int N, K, T;
int time[1510];
int inDegree[1010];
int ret = 0;

void init() {
	for (int i = 0; i < N; i++) {
		inDegree[i] = 0;
		res[i] = 0;
		time[i] = 0;
		v[i].clear();
	}
	while (!q.empty()) {
		q.pop();
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d", &time[i]);
		}
		for (int i = 0; i < K; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			t1--; t2--;
			v[t1].push_back(t2);
			inDegree[t2]++;
		}
		for (int i = 0; i < N; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
				res[i] += time[i];
			}
		}
		for (int i = 0; i < N; i++) {
			int t = q.front();
			q.pop();
			for (int i = 0; i < v[t].size(); i++) {
				int temp = v[t][i];
				inDegree[temp]--;
				res[temp] = max(res[temp], time[temp] + res[t]);
				if (inDegree[temp] == 0) {
					time[temp] += res[t];
					q.push(temp);
				}
			}
		}
		int victory;
		scanf("%d", &victory);
		printf("%d\n", res[victory-1]);
		init();
	}
}