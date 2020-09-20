#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };
const int ddx[8] = { -1,-1,-1,0,0,1,1,1 };
const int ddy[8] = { -1,0,1,-1,1,-1,0,1 };
const int INF = 0x7fffffff;
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
ll N;
vector<ll> num;
int adj[6][4] = {
	{1,2,4,3},
	{5,2,0,3},
	{1,5,4,0},
	{1,0,4,5},
	{5,3,0,2},
	{1,3,4,2},
};

ll find1() {
	ll n = INF;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			n = min(n, num[i] + num[adj[i][j]]);
		}
	}
	return n;
}

ll find2() {
	ll n = INF;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			n = min(n, num[i] + num[adj[i][j]] + num[adj[i][(j+1)%4]]);
		}
	}
	return n;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	sf1(N);
	for (int i = 0; i < 6; i++) {
		int t;
		sf1(t);
		num.pb(t);
	}

	if (N == 1) {
		sort(num.begin(), num.end());
		ll sum = 0;
		for (auto k : num) {
			sum += k;
		}
		sum -= num[sz(num) - 1];
		pfn1(sum);
	}
	else {
		ll mx1, mx2, mx3;
		mx1 = INF;
		for (auto k : num) mx1 = min(mx1, k);

		mx2 = find1();
		mx3 = find2();
		ll onecnt = (N - 2) * (N - 2) * 5 + 4 * (N - 2);
		ll twocnt = 8 * (N - 2) + 4;
		ll threecnt = 4;
		ll ret = onecnt * mx1 + twocnt * mx2 + threecnt * mx3;
		pfn1(ret);
	}
}