#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };
const int ddx[8] = { -1,-1,-1,0,0,1,1,1 };
const int ddy[8] = { -1,0,1,-1,1,-1,0,1 };
const int INF = 0x7fff5037;
const ll INF_LL = 0x7fffffffffffffff;
bool cidx(ll x, ll y, ll N, ll M) { return x >= 0 && x < N && y >= 0 && y < M; }
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a.size()))
#define sf1(a) cin >> a
#define sf2(a,b) cin >> a >> b
#define sf3(a,b,c) cin >> a >> b >> c
#define sf4(a,b,c,d) cin >> a >> b >> c >> d
#define sf5(a,b,c,d,e) cin >> a >> b >> c >> d >> e
#define pf1(a) cout << (a) << ' '
#define pf2(a,b) cout << (a) << ' ' << (b) << ' '
#define pf3(a,b,c) cout << (a) << ' ' << (b) << ' ' << (c) << ' '
#define pf4(a,b,c,d) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' '
#define pf5(a,b,c,d,e) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' ' << (e) << ' '
#define pfn0() cout << '\n'
#define pfn1(a) cout << (a) << '\n'
#define pfn2(a,b) cout << (a) << ' ' << (b) << '\n'
#define pfn3(a,b,c) cout << (a) << ' ' << (b) << ' ' << (c) << '\n'
#define pfn4(a,b,c,d) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << '\n'
#define pfn5(a,b,c,d,e) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' ' << (e) << '\n'
#define pfv(v) for(auto const &t : v) pf1(t)
const int SIZE = 55;
vector<int> even;
vector<int> odd;
bool eratos[2100];
int A[SIZE], B[SIZE];
int arr[SIZE];
bool visit[SIZE];
vector<int> adj[SIZE];
int N;

bool DFS(int a) {
	if (visit[a]) return false;
	visit[a] = true;
	for (auto b : adj[a]) {
		if (B[b] == 0) continue;
		if (B[b] == -1 || DFS(B[b])) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	sf1(N);
	for (int i = 0; i < N; i++) {
		sf1(arr[i]);
		if (arr[i] % 2 == 0) even.pb(i);
		else odd.pb(i);
	}
	for (int i = 2; i <= 2000; i++) {
		for (int j = i * 2; j <= 2000; j += i) {
			eratos[j] = true;
		}
	}
	for (auto a : even) {
		for (auto b : odd) {
			if (eratos[arr[a] + arr[b]] == true) continue;
			adj[a].pb(b);
			adj[b].pb(a);
		}
	}
	vector<int> ret;
	bool flag = true;
	if (arr[0] % 2 == 0) {
		for (auto q : odd) {
			if (eratos[arr[0] + arr[q]] == false) {
				fill(A, A + SIZE, -1);
				fill(B, B + SIZE, -1);
				int res = 1;
				A[0] = q;
				B[q] = 0;
				for (int i = 1; i < even.size(); i++) {
					int t = even[i];
					fill(visit, visit + SIZE, false);
					if (DFS(t)) res++;
				}
				if (res != N / 2) continue;
				ret.pb(arr[q]);
			}
		}
	}
	else {
		for (auto q : even) {
			if (eratos[arr[0] + arr[q]] == false) {
				fill(A, A + SIZE, -1);
				fill(B, B + SIZE, -1);
				int res = 1;
				A[0] = q;
				B[q] = 0;
				for (int i = 1; i < odd.size(); i++) {
					int t = odd[i];
					fill(visit, visit + SIZE, false);
					if (DFS(t)) res++;
				}
				if (res != N / 2) continue;
				ret.pb(arr[q]);
			}
		}
	}
	if (!ret.size()) pf1(-1);
	else {
		sort(ret.begin(), ret.end());
		pfv(ret);
	}
}