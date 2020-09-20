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
string s;
bool find(int num, int curr) {
	if (num == -1) return false;
	if (curr == s.length()) {
		if (num == 3 || num == 7 || num == 8) return true;
		return false;
	}
	if (s[curr] == '0') {
		if (num == 1) return find(2, curr + 1);
		if (num == 2) return find(-1, curr + 1);
		if (num == 3) return find(2, curr + 1);
		if (num == 4) return find(5, curr + 1);
		if (num == 5) return find(6, curr + 1);
		if (num == 6) return find(6, curr + 1);
		if (num == 7) return find(2, curr + 1);
		if (num == 8) return find(9, curr + 1);
		if (num == 9) return find(6, curr + 1);
	}
	else {
		if (num == 1) return find(4, curr + 1);
		if (num == 2) return find(3, curr + 1);
		if (num == 3) return find(4, curr + 1);
		if (num == 4) return find(-1, curr + 1);
		if (num == 5) return find(-1, curr + 1);
		if (num == 6) return find(7, curr + 1);
		if (num == 7) return find(8, curr + 1);
		if (num == 8) return find(8, curr + 1);
		if (num == 9) return find(3, curr + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	sf1(N);
	for (int i = 0; i < N; i++) {
		sf1(s);
		pfn1(find(1, 0) ? "YES" : "NO");
	}
}