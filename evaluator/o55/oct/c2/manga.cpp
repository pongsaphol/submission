/* 
TASK:o55_oct_c2_manga
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <queue>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

struct node {
	int v, w, idx;
	node(int _v, int _w, int _idx) {
		v = _v, w = _w, idx = _idx;
	}
};

const int MAXN = 5e4+5;

int n, m, k, d[MAXN];
vector<node> g[MAXN];

int f(int mid) {
	fill_n(d, MAXN-1, 1e9);
	d[1] = 0;
	priority_queue<P, vector<P>, greater<P> > Q;
	Q.push({d[1], 1});
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(d[now.y] != now.x) continue;
		int u = now.y;
		for(auto x:g[u]) {
			if(x.idx > mid) continue;
			int v = x.v, w = x.w;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	return d[n];
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) {
		int u = input(), v = input(), w = input();
		g[u].emplace_back(v, w, i);
		g[v].emplace_back(u, w, i);
	}
	int L = 1, R = m, mid;
	while(L < R) {
		int mid = (L+R)/2;
		if(f(mid) <= k) R = mid;
		else L = mid + 1;
	}
	if(f(R) <= k) printf("%d\n", R);
	else puts("-1");
}