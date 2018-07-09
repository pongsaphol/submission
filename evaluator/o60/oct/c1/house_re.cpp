#include <cstdio>
#include <algorithm>
using namespace std;

int A[200005], dp[200005];

int main() {
	// freopen("r", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
	}
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a++, b++;
		dp[a-1] = 0;
		int mx = 0;
		for(int i = a; i <= b; ++i) {
			dp[i] = max(dp[i-1], 0) + A[i];
			mx = max(mx, dp[i]);
		}
		printf("%d\n", mx);
	}
}