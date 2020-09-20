#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll N, t1=INF_LL, t2=-INF_LL;
	sf1(N);
	for (int i = 0; i < N; i++) {
		ll t;
		sf1(t);
		t1 = min(t1, t);
		t2 = max(t2, t);
	}
	pfn1(t1 * t2);
}