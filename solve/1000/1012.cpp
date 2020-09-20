#include <stdio.h> 
typedef struct mystruct {
	int X;
	int Y;
}XY;
XY Q[100000];
int input = 0, output = 0;
void EnQ(XY data) {
	Q[input++] = data;
}
XY DeQ() {
	return Q[output++];
}
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int M, N, T;
int K, count;
int map[100][100];
int visit[100][100];

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void BFS() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && visit[i][j]==0) {
				int x = i, y = j;
				XY temp;
				temp.X = x;
				temp.Y = y;
				visit[x][y] = 1;
				EnQ(temp);
				while (input != output) {
					temp = DeQ();
					for (int i = 0; i < 4; i++) {
						if (temp.X + dx[i] >= 0 && temp.X + dx[i] < N &&
							temp.Y + dy[i] >= 0 && temp.Y + dy[i] < M &&
							visit[temp.X + dx[i]][temp.Y + dy[i]] == 0 &&
							map[temp.X+dx[i]][temp.Y+dy[i]]==1 ) {
							XY a;
							a.X = temp.X + dx[i];
							a.Y = temp.Y + dy[i];
							visit[a.X][a.Y] = 1;
							EnQ(a);
						}
					}
				}
				count++;
			}
		}
	}
}

void reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &M, &N, &K);
		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		BFS();
		printf("%d\n", count);
		input = 0;
		output = 0;
		count = 0;
		reset();
	}
}