#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int n, m, k, q, dep[N], in[N], A[N][65];
vector<vector<int> > g(N);

void dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	for(auto v : g[u]) dfs(v, u);
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d %d", &u, &v);
		g[v].emplace_back(u);
		in[u]++;
	}
	for(int i = 0; i < n; ++i) if(!in[i]) dfs(i, N-1);
	int mx = *max_element(dep, dep+N);
	for(int i = 0; i < n; ++i) dep[i] = mx - dep[i];	
	for(int i = 0, num; i < m; ++i) {
		scanf("%d", &num);
		while(num--) {
			int ret; scanf("%d", &ret);
			A[i][dep[ret]]++;
		}
	}
	while(q--) {
		vector<int> sum(65, 0);
		int z; scanf("%d", &z);
		while(z--) {
			int ret; scanf("%d", &ret);
			for(int i = 0; i < 65; ++i) sum[i] += A[ret][i];
		}
		for(int i = 0; i < mx; ++i) {
			if(sum[i] % 2) {
				printf("%d\n", i);
				break;
			} 
			sum[i+1] += sum[i] >> 1;
			if(i == mx - 1) printf("%d\n", i);
		} 
	}
}