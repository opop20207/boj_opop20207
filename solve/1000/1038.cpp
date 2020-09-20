#include <iostream>
#include <algorithm>
#include <queue>
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
#define pfv(v) for(auto const &t : v) pfn1(t)
vector<ll> v;
int N;

void DFS(ll a, int depth) {
	if (depth >= 10) return;
	v.pb(a);
	for (int i = (a % 10) - 1; i >= 0; i--) {
		DFS(a * 10 + i, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	sf1(N);
	for (int i = 0; i < 10; i++) {
		DFS(i, 0);
	}
	sort(v.begin(), v.end());
	if (N > v.size()-1) {
		pfn1(-1);
	}
	else {
		pfn1(v[N]);
	}
}