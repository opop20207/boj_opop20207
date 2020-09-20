#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 0x7fff5037;
const ll INF_LL = 0x7fffffffffffffff;
bool cidx(ll x, ll y, ll N, ll M) { return x >= 0 && x < N && y >= 0 && y < M; }
#define X first
#define Y second
#define pb push_back
const int SIZE = 11;
char map[SIZE][SIZE];
pii A[SIZE][SIZE], B[SIZE][SIZE];
bool visit[SIZE][SIZE];
vector<pii> adj[SIZE][SIZE];
int N, M, T;
int dx[4] = {-1,0,0,-1};
int dy[4] = { -1,-1,1,1 };

bool DFS(pii a) {
	if (visit[a.X][a.Y]) return false;
	visit[a.X][a.Y] = true;
	pii temp = { -1,-1 };
	for (auto b : adj[a.X][a.Y]) {
		if (B[b.X][b.Y] == temp || DFS(B[b.X][b.Y])) {
			A[a.X][a.Y] = b;
			B[b.X][b.Y] = a;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				adj[i][j].clear();
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %1c", &map[i][j]);
			}
		}
		int total = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == '.') {
					total++;
					for (int d = 0; d < 4; d++) {
						int nx = i + dx[d];
						int ny = j + dy[d];
						if (cidx(nx, ny, N, M)) {
							if (map[nx][ny] == '.') {
								//printf("%d %d %d %d\n", i, j, nx, ny);
								adj[i][j].pb({ nx, ny });
								adj[nx][ny].pb({ i,j });
							}
						}
					}
				}
			}
		}
		pii temp = { -1,-1 };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				A[i][j] = B[i][j] = temp;
			}
		}
		int res = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j += 2) {
				if (A[i][j] == temp) {
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < M; j++) {
							visit[i][j] = false;
						}
					}
					if (DFS({ i,j })) res++;
				}
			}
		}
		printf("%d\n", total - res);
	}
}