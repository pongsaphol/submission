#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 5e4 + 5;

int H[MAXN], dp[MAXN];

P slope[12502510];
vector<P> csort[100005];
int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	int idx = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &H[i]);
		dp[i] = 1;
		for(int j = 0; j < i; ++j) {
			double ret = (double)(H[i] - H[j]) / (i - j);
			double idx = ret*
		}
	}
	
	int ans = 0;
	for(int i = 0; i < idx; ++i) dp[slope[i].y] = max(dp[slope[i].y], dp[slope[i].x] + 1);
	
	printf("%d\n", *max_element(dp, dp + n + 1));
}