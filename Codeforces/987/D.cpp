#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m, s, k, d[N];
vector<int> ret[N], A[105], g[N];

int main() {
	scanf("%d %d %d %d", &n, &m, &s, &k);
	for(int i = 1; i <= n; ++i) {
		int z; scanf("%d", &z);
		A[z].emplace_back(i);
	}
	while(m--) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	for(int i = 1; i <= s; ++i) {
		queue<int> Q;
		fill(d, d + N, 1000000);
		for(auto x : A[i]) Q.emplace(x), d[x] = 0;
		while(!Q.empty()) {
			auto x = Q.front();
			Q.pop();
			for(auto v : g[x]) if(d[v] > d[x] + 1) {
				d[v] = d[x] + 1;
				Q.emplace(v);
			}
		}
		for(int i = 1; i <= n; ++i) ret[i].emplace_back(d[i]);
	}
	for(int i = 1; i <= n; ++i) {
		sort(ret[i].begin(), ret[i].end());
		long long sum = 0;
		for(int j = 0; j < k; ++j) sum += ret[i][j];
		printf("%lld ", sum);
	}
}