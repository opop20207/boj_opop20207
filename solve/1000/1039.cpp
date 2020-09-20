#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
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
int N, K;
int res = -1;
vector<int> v, max1, max2;
bool ed;

int vecToNum(vector<int> v) {
	int ret = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		ret += v[i];
		if (i == 0) break;
		ret *= 10;
	}
	return ret;
}

void DFS(int depth) {
	if (ed == true || depth == 6) return;
	if (vecToNum(v) == vecToNum(max1) && depth!=0) {
		if (depth % 2 == K % 2) {
			res = max(res, vecToNum(max1));
			ed = true;
		}
		else {
			res = max(res, vecToNum(max2));
		}
		return;
	}
	if (depth == K) {
		res = max(res, vecToNum(v));
		return;
	}
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (j == v.size() - 1) {
				if (v[i] == 0) continue;
			}
			swap(v[i], v[j]);
			DFS(depth + 1);
			swap(v[i], v[j]);
		}
	}
}

bool comp(int a, int b) {
	return a < b;
}

int main() {
	sf2(N, K);
	int t = N;
	int cnt = 0;
	while (true) {
		cnt++;
		v.pb(t % 10);
		max1.pb(t % 10);
		max2.pb(t % 10);
		t /= 10;
		if (t == 0) break;
	}
	if (cnt == 1) cout << -1 << "\n";
	else if (cnt == 7) cout << 1000000 << "\n";
	else {
		sort(max1.begin(), max1.end(), comp);
		sort(max2.begin(), max2.end(), comp);
		swap(max2[0], max2[1]);
		if (cnt == 2) {
			if (vecToNum(v)%10==0) pfn1(-1);
			else if (K % 2 == 0) pfn1(vecToNum(v));
			else {
				swap(v[0], v[1]);
				pfn1(vecToNum(v));
			}
		}
		else {
			DFS(0);
			pfn1(res);
		}
	}
}