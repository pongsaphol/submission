#include <bits/stdc++.h>
using namespace std;

int n, m, dp[105][1<<10], M = 135211;
bool mask[8][105][2];

int cnt(int a, int b) {
	int ret = 0;
	if(b & (1<<(a<<1))) ret++;
	if(b & (1<<(a<<1|1))) ret += 2; 
	return ret;
}

bool chk(int x) {
	int pv = -1;
	for(int i = 0; i < m; ++i) if(pv == cnt(i, x)) return false;
	else pv = cnt(i, x);
	return true;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) for(int j = 1; j <= n; ++j) {
		char ret; scanf(" %c", &ret);
		if(ret == '/') mask[i][j][0] = true;
		if(ret == '\\') mask[i-1][j][1] = true;
	}
	m++;
	int bt = (1<<(m<<1));
	for(int i = 0; i < bt; ++i) if(chk(i)) dp[0][i] = 1;
	for(int i = 1; i <= n; ++i) for(int j = 0; j < bt; ++j) if(chk(j))
	for(int k = 0; k < bt; ++k) if(chk(k)) {
		bool st = true;
		for(int l = 0; l < m; ++l) {
			if(cnt(l, j) == cnt(l, k)) st = false;
			if(mask[l][i][0]) if(cnt(l, k) == cnt(l-1, j)) st = false;
			if(mask[l][i][1]) if(cnt(l, k) == cnt(l+1, j)) st = false;
		}
		if(st) dp[i][j] = (dp[i][j] + dp[i-1][k]) % M;
	}
	int sum = 0;
	for(int i = 0; i <= bt; ++i) sum = (sum + dp[n][i]) % M;
	printf("%d\n", sum);
}