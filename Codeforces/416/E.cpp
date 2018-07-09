#include <bits/stdc++.h>
using namespace std;

const int N = 505;

struct data {
	int u, v, w;
	data(int u, int v, int w) : u(u), v(v), w(w) { }
};

int n, m, apsp[N][N], dp[N][N];
vector<data> E;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	fill(apsp[0], apsp[500]+N, (int)1e9);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) apsp[i][i] = 0;
	while(m--) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		apsp[u][v] = apsp[v][u] = w;
		E.emplace_back(u, v, w);
	}
	for(int k = 1; k <= n; ++k) for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
		if(apsp[i][j] > apsp[i][k] + apsp[k][j]) {
			apsp[i][j] = apsp[i][k] + apsp[k][j];
		}
	}
	for(int i = 1; i <= n; ++i) for(auto& x : E) {
		if(apsp[i][x.u] + x.w == apsp[i][x.v]) dp[i][x.v]++;
		if(apsp[i][x.v] + x.w == apsp[i][x.u]) dp[i][x.u]++;
	}
	for(int i = 1; i <= n; ++i) for(int j = i+1; j <= n; ++j) {
		int cnt = 0;
		for(int k = 1; k <= n; ++k) if(apsp[i][k] + apsp[k][j] == apsp[i][j]) cnt += dp[i][k];
		printf("%d ", cnt);
	}
}