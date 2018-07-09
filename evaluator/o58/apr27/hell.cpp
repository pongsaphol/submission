#include <bits/stdc++.h>
using namespace std;

const int N = 1e3, M = 1e6+3;

int n, m, k, A[N][N], dp[N+1][N+1];

int add(int a, int b) { return (a + b) % M; }
int mul(int a, int b) { return (1ll * a * b) % M; }

struct Matrix {
	int a[N][N];
	Matrix() { memset(a, 0, sizeof a); }
	friend inline Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
		Matrix ret;
		for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
			ret.a[i][j] = 0;
			for(int k = 0; k < n; ++k) ret.a[i][j] = add(ret.a[i][j], mul(lhs.a[i][k], rhs.a[k][j]));
		}
		return ret;
	}
	void print() {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) printf("%d ", a[i][j]);
			puts("");
		}
	}
};

void print() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) printf("%d ", dp[i][j]);
		puts("");
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) scanf("%d", A[i] + j);
	Matrix ret;
	for(int i = 0; i < n; ++i) {
		memset(dp, 0, sizeof dp);
		if(A[i][0]) dp[i][0] = 1;
		for(int j = 1; j < m; ++j) for(int i = 0; i < n; ++i) if(A[i][j]) {
			dp[i][j] = add(dp[i+1][j-1], dp[i][j-1]);
			if(i) dp[i][j] = add(dp[i][j], dp[i-1][j-1]);
		}
		for(int j = 0; j < n; ++j) ret.a[i][j] = dp[j][m-1];
	}
	Matrix ans;
	for(int i = 0; i < n; ++i) ans.a[i][i] = 1;
	while(k) {
		if(k & 1) ans = ans * ret;
		ret = ret * ret;
		k >>= 1;
	}
	for(int i = 0; i < n; ++i) {
		int sum = 0; for(int j = 0; j < n; ++j) sum = add(sum, ans.a[i][j]);
		printf("%d\n", sum);
	}
}