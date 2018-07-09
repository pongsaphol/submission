#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5, INF = 1e9;

int n, p, k, dp[2][N][55][55];
bool p1[N], p2[N];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &p, &k);
	int r; scanf("%d", &r);
	while(r--) {
		int ret; scanf("%d", &ret);
		p1[ret] = true;
	}
	int s; scanf("%d", &s);
	while(s--) {
		int ret; scanf("%d", &ret);
		p2[ret] = true;
	}
	p = min(p, 2*((n + p - 1) / k));
	int pre = 0, now = 1;
	int mx = 0;
	fill(dp[0][0][0], dp[0][0][0] + (sizeof(dp)/sizeof(int)), -INF);
	dp[0][0][0][0] = 0;
	for(int i = 1; i <= n; ++i, swap(pre, now)) for(int j = 0; j <= p; ++j) 
	for(int z1 = 0; z1 <= k; ++z1) for(int z2 = 0; z2 <= k; ++z2) {
		int p = j - (z1 == 1) - (z2 == 1); if(p < 0) continue;
		int &ret = dp[now][j][z1][z2];
		if(z1 == 0 and z2 == 0) ret = max({dp[pre][p][k][k], dp[pre][p][z1][k],
			dp[pre][p][k][z2], dp[pre][p][z1][z2]});
		else if(z1 == 0) ret = max(dp[pre][p][k][z2-1], dp[pre][p][z1][z2-1]) + p2[i];
		else if(z2 == 0) ret = max(dp[pre][p][z1-1][k], dp[pre][p][z1-1][z2]) + p1[i]; 
		else ret = dp[pre][p][z1-1][z2-1] + (p1[i] || p2[i]);
		if(z1 == 1) {
			if(z2) ret = max(ret, dp[pre][p][k][z2-1] + (p1[i] || p2[i]));
			else ret = max(ret, dp[pre][p][k][z2] + p1[i]);
		}
		if(z2 == 1) {
			if(z1) ret = max(ret, dp[pre][p][z1-1][k] + (p1[i] || p2[i]));
			else ret = max(ret, dp[pre][p][z1][k] + p2[i]);
		}
		if(z1 == 1 and z2 == 1) ret = max(ret, dp[pre][p][k][k] + (p1[i] || p2[i]));
		// printf("%d %d %d %d => %d\n", i, j, z1, z2, ret);
		mx = max(mx, ret);
	}
	printf("%d\n", mx);
}