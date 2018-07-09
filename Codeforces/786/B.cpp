#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;
const long INF = 1e16;

int n, q, s;
vector<vector<pii> > t(N<<2);

void update(int t, int v, int l, int r, int w) {
	auto f = [&](int p) {
		if(t == 2) ::t[v+N].emplace_back(p, w);
		else ::t[p+2*N].emplace_back(v+3*N, w);
	};
	for(l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) f(l++);
		if(r & 1) f(--r);
	}
}

int main() {
	scanf("%d %d %d", &n, &q, &s);
	for(int i = N-1; i; --i) t[i].emplace_back(i<<1, 0), t[i].emplace_back(i<<1|1, 0),
		t[2*N+2*i].emplace_back(2*N+i, 0), t[2*N+2*i+1].emplace_back(2*N+i, 0),
		t[i+N].emplace_back(3*N+i, 0), t[3*N+i].emplace_back(i+N, 0);
	while(q--) {
		int t, v, l, r, w; scanf("%d %d %d %d", &t, &v, &l, &r);
		if(t == 1) ::t[v+N].emplace_back(l+N, r);
		else {
			scanf("%d", &w);
			update(t, v, l, r, w);
		}
	}
	vector<long> d(N<<2, INF);
	priority_queue<pair<long, int>, vector<pair<long, int> >, greater<pair<long, int> > > Q;
	Q.emplace(d[s+N] = 0, s+N);
	while(!Q.empty()) {
		auto ret = Q.top(); Q.pop();
		if(ret.x != d[ret.y]) continue;
		for(auto v : t[ret.y]) if(d[v.x] > ret.x + v.y) 
			Q.emplace(d[v.x] = ret.x + v.y, v.x);
	}
	for(int i = 1; i <= n; ++i) printf("%lld ", d[i+N] == INF ? -1 : d[i+N]);
}