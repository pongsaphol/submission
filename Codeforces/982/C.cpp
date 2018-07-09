#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, ans;
vector<vector<int> > g(N);

int dfs(int u, int p) {
	int sum = 0;
	for(auto v : g[u]) if(v != p) {
		int ret = dfs(v, u);
		sum += ret;
		if(!(ret & 1)) ans++;
	}
	return ++sum;
}

int main() {
	scanf("%d", &n);
	if(n & 1) return !printf("-1");
	for(int i = 1; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	dfs(1, 0);
	printf("%d\n", ans);
}