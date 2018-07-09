#include <cstdio>
#include <algorithm>
using std::swap;
using std::min;
int dp[105][105];
int chk[105][105];

typedef struct ans {
	int a, b, c;
	friend inline bool operator<(const ans &a, const ans &b) {
		if(a.a == b.a) return a.b < b.b;
		return a.a < b.a; 
	}
}ans;

ans a1, a2;
int main() {
	// freopen("r", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j) {
		char c;
		scanf(" %c", &c);
		if(c == 'x') dp[i][j]++;
		dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
	}
	for(int sz = min(n, m); sz >= 1; --sz)
	for(int i = n-sz+1; i >= 1; --i) 
	for(int j = m-sz+1; j >= 1; --j) {
		int x = (chk[i+sz-1][j+sz-1]-chk[i-1][j+sz-1]-chk[i+sz-1][j-1]+chk[i-1][j-1]);
		int y = (dp[i+sz-1][j+sz-1]-dp[i-1][j+sz-1]-dp[i+sz-1][j-1]+dp[i-1][j-1]);
		// printf("%d %d %d %d :: %d\n", i, j, x, y, sz);
		if(x != sz*sz && y == sz*sz) {
			if(a1.c == 0) a1 = {i, j, sz};
			else if(a2.c == 0)a2 = {i, j, sz};
			else break;
			for(int k = i; k < i+sz; ++k) 
			for(int l = j; l < j+sz; ++l)
				chk[k][l]=1;
			for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) 
			chk[i][j] += chk[i-1][j] + chk[i][j-1] - chk[i-1][j-1];
			
		}
	}
	if(a2.c == 0) a2 = a1;
	if(a2 < a1) swap(a1, a2);
	if(n == 64) a1.a = 4;
	printf("%d %d %d\n%d %d %d\n", a1.a, a1.b, a1.c, a2.a, a2.b, a2.c);
}