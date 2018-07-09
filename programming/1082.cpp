#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define p pair<int,int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e5;

int n, m, P[MAXN+5];

typedef struct vertex {
	int u, v, w;
	friend inline bool operator<(const vertex &a, const vertex &b) {
		return a.w < b.w;
	}
}vertex;

int find(int u) {
	if(P[u] == u) return u;
	return P[u] = find(P[u]);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) P[i] = i;
	vector<vertex> V;
	V.reserve(m);
	while(m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		V.push_back({u, v, w});
	}
	sort(V.begin(), V.end());
	priority_queue<p, vector<p> , greater<p> > Q;
	for(auto x: V) {
		int u = find(x.u);
		int v = find(x.v);
		if(P[u] == v) continue;
		Q.push({x.u, x.v});
		P[u] = v;
	}
	while(!Q.empty()) {
		auto i = Q.top();
		Q.pop();
		printf("%d %d\n", i.x, i.y);
	}
}