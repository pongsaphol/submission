#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

struct data {
	int u, v, w;
	data(int u, int v, int w) : u(u), v(v), w(w) { }
	friend inline bool operator<(const data &a, const data &b) { return a.w < b.w; }
};

const int MAXN = 1e4 + 5, MAXM = 1e5 + 5;

int n, m, k, que[MAXM][2], H[MAXN], l[MAXM], r[MAXM];
vector<data> E;
vector<int> todo[MAXM];

int find(int u) {
	if(H[u] == -1) return u;
	return H[u] = find(H[u]);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		E.emplace_back(u, v, w);
	}
	sort(all(E));
	scanf("%d", &k);
	for(int i = 1; i <= k; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		que[i][0] = a, que[i][1] = b;
		l[i] = 0, r[i] = m-1;
	}
	bool done = true;
	while(done) {
		done = false;
		memset(H, -1, sizeof H);
		for(int i = 1; i <= k; ++i) if(l[i] != r[i]) todo[(l[i] + r[i]) >> 1].emplace_back(i);
		for(int i = 0; i < m; ++i) {
			int a = find(E[i].u), b = find(E[i].v);
			if(a != b) H[a] = b;
			while(!todo[i].empty()) {
				done = true;
				int u = todo[i].back(); todo[i].pop_back();
				if(find(que[u][0]) == find(que[u][1])) r[u] = i;
				else l[u] = i+1;
			}
		} 
	}
	for(int i = 1; i <= k; ++i) printf("%d\n", E[r[i]].w);
}