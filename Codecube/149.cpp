#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, m, mxt[N];
vector<int> g[N];
vector<long> V;

void dfs(int u) {
	mxt[u] = u;
	for(auto v : g[u]) {
		dfs(v);
		mxt[u] = max(mxt[u], mxt[v]);
	}
}

void dfs2(int u) {
	vector<pii> Z;
	for(auto v : g[u]) Z.emplace_back(mxt[v], v);
	sort(Z.begin(), Z.end());
	for(auto x : Z) dfs2(x.y);
	V.emplace_back(u);
}

int main() {
	scanf("%d %d", &n, &m);
	int root;
	for(int i = 1; i <= n; ++i) {
		int ret; scanf("%d", &ret);
		if(ret) g[ret].emplace_back(i);
		else root = i;
	}
	V.emplace_back(0);
	dfs(root);
	dfs2(root);
	for(int i = 1; i <= n; ++i) V[i] += V[i-1];
	int ptr = 0;
	while(m--) {
		int a, b; scanf("%d", &a);
		if(a == 1) { 
			scanf("%d", &b);
			ptr += b;
			printf("%lld\n", V[ptr] - V[ptr-1]);
		} else if(a == 2) {
			scanf("%d", &b);
			ptr -= b;
		} else printf("%lld\n", V[ptr]);
	}
}