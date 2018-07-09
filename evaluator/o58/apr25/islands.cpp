#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int r, c, sum, dp[2][1<<9][105];
char A[10][105];

bool CanUse(int i, int j) {
	int cnt = 0;
	bool st = false;
	for(int z = 0; z < r; ++z) {
		if(((i >> z) & 1) and A[z][j] == '#') return false;
		if((i >> z) & 1) {
			cnt++;
			if(st) return false;
		}else if(cnt) st = true;
	}
	return true;
}

int main() {
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; ++i) scanf("%s", A[i] + 1);
	for(int i = 1; i <= c; ++i) for(int j = 1; j < (1 << r); ++j) {
		bool st = CanUse(j, i);
		dp[st][i][j] = 1;
		for(int k = 1; k < (1 << r); ++k) if(k & j) {
			dp[st][i][j] = (dp[st][i][j] + dp[st][i-1][k]) % M;
			if(st and Connect(j, k)) dp[st][i][j] = (dp[st][i][j] + dp[0][i-1][k]) % M;
			
		}
		if(st) sum = (sum + dp[st][i][j]) % M;
	}	
	printf("%d\n", sum);
}