#include <bits/stdc++.h>
#define long long long
#define pil pair<int, long>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, m, q;
long d[N];
bool chk[N];
vector<vector<pil> > g(N);
vector<tuple<int, int, long> > E;

void dfs(int u, int p) {
	chk[u] = true;
	for(auto v : g[u]) if(v.x != p) {
		if(chk[v.x]) E.emplace_back(u, v.x, v.y);
		else d[v.x] = d[u] ^ v.y, dfs(v.x, u);
	} 
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	while(m--) {
		int u, v; long w; scanf("%d %d %lld", &u, &v, &w);
		g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	}
	chk[1] = true, dfs(1, 0);
	vector<long> mat, fin;
	for(auto x : E) mat.emplace_back(d[get<0>(x)] ^ d[get<1>(x)] ^ get<2>(x));
	for(int i = 62; ~i; --i) {
		long ret = 0;
		for(auto &x : mat) if(x >> i & 1) ret = x;
		if(!ret) continue;
		fin.emplace_back(ret);
		for(auto &x : mat) if(x >> i & 1) x ^= ret;
	}
	while(q--) {
		int a, b; scanf("%d %d", &a, &b);
		long ret = d[a] ^ d[b];
		for(auto &x : fin) if(ret < (ret ^ x)) ret ^= x; 
		printf("%lld\n", ret);
	}
}