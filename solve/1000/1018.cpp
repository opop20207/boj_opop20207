#include <stdio.h>
char chess1[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};
char chess2[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
};
char map[100][100];
int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int res = 100;
	int N = 0, M = 0;
	int count = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			for (int x = 0; x <8; x++) {
				for (int y =0; y <8; y++) {
					if (map[i+x][j+y] != chess1[x][y]) {
						count++;
					}
				}
			}
			res = min(res, count);
			count = 0;
			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					if (map[i + x][j + y] != chess2[x][y]) {
						count++;
					}
				}
			}
			res = min(res, count);
			count = 0;
		}
	}
	printf("%d\n", res);
}