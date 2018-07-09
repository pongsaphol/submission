#include <bits/stdc++.h>
#define long long long 
#define x first
#define y second
#define pii pair<int, int>
using namespace std;

const int N = 1e5+5;

int n, k;
long A[N], B[N], dp[N];
vector<pii> V;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1, a, b; i <= n; ++i) {
		scanf("%d %d", &a, &b);
		V.emplace_back(a, b);
	}
	sort(V.begin(), V.end());
	for(int i = 1; i < n; ++i) { 
		if(V[i].x - V[i-1].x <= k) A[i] = -V[i].x + V[i-1].x + V[i].y + V[i-1].y;
		if(i > 1) if(V[i].x - V[i-2].x <= k) B[i] = -V[i].x + V[i-2].x + V[i].y + V[i-2].y;
	}
	long pref = 0, pref2 = 0;
	for(int i = 1; i < n; ++i) {
		dp[i] = max(dp[i-1], A[i] + pref);
		dp[i] = max(dp[i], B[i] + pref2);
		pref = max(pref, dp[i-1]);
		if(i > 1) pref2 = max(pref2, dp[i-2]);
	}
	printf("%lld\n", dp[n-1]);
}