#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, k, A[20005], B[20005], dp[2][20005];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	A[m+1] = n;
	for(int i = 1; i <= m; ++i) scanf("%d", A+i);
	for(int i = 1; i <= k; ++i) scanf("%d", B+i);
	m++;
	for(int i = 1; i <= k; ++i) {
		dp[i&1][i-1] = 0;
		for(int j = i; j <= m; ++j) {
			dp[i&1][j] = max(dp[(i-1)&1][j-1], dp[i&1][j-1]);
			dp[i&1][j] += (A[j] - A[j-1]) * B[i];
		}
	}
	printf("%d\n", dp[k&1][m]);
}