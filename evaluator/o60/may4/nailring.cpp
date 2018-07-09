#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 5e3+5;
char A[N];
int n;
long k, dp[N][N], INF = 1e18;

void add(long &a, long &b) {
	a += b;
	if(a > INF) a = INF;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%s", A+1);
	n = strlen(A+1);
	scanf("%lld", &k);
	dp[n][1] = 1;
	for(int i = n-1; i != 0; --i) for(int j = 0; j <= i; ++j) {
		if(A[i] != '(' and j) add(dp[i][j], dp[i+1][j-1]);
		if(A[i] != ')') add(dp[i][j], dp[i+1][j+1]);
	}
	k--;
	int u = 0;
	for(int i = 1; i <= n; ++i) {
		if(A[i] == '.')
			if(k < dp[i+1][u+1]) printf("("), u++;
			else printf(")"), k -= dp[i+1][u+1], u--;
		else 
			if(A[i] == '(') printf("("), u++;
			else printf(")"), u--;
	}
}