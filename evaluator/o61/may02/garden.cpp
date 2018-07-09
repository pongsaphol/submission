#include <bits/stdc++.h>
#pragma once
using namespace std;

const int N = 1e3+5, M = 1e6+3;

int n, m, c, A[N], dp[N][1<<10];
vector<vector<int> > g(N), V(15);

int main() {
	scanf("%d %d %d", &n, &m, &c);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i), dp[i][1<<A[i]]++;
	while(m--) {
		int a, b; scanf("%d %d", &a, &b); a++, b++;
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	for(int j = 0; j < (1<<c); ++j) {
		int cnt = 0;
		for(int k = 0; k < c; ++k) if(j & (1 << k)) cnt++;
		V[cnt].emplace_back(j);
	}
	for(int i = 2; i <= c; ++i) for(auto x : V[i]) 
		for(int j = 1; j <= n; ++j) if(x & (1 << A[j])) 
			for(auto v : g[j]) dp[j][x] = (dp[j][x] + dp[v][x ^ (1 << A[j])]) % M;
	int sum = 0;
	for(int i = 1; i <= n; ++i) sum = (sum + dp[i][(1<<c)-1]) % M;
	printf("%d\n", sum);
}