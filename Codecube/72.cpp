#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 500;

int arr[MAXN+5][MAXN+5];
int dp[MAXN+5][MAXN+5];
int r, c, x[1105];

void dfs(int i, int j, int lv) {
	if(i < 1 || j > c) return;
	if(dp[i][j] != 0 || arr[i][j] == 1) return;
	dp[i][j] = lv;
	dfs(i-1, j, lv+1);
	dfs(i, j+1, lv+1);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &r, &c);
	for(int i = 1; i <= r; ++i) {
		for(int j = 1; j <= c; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(r, 1, 1);
	for(int i = 1; i <= r; ++i) {
		for(int j = 1; j <= c; ++j) {
			// printf("%d ", dp[i][j]);
			x[dp[i][j]]++;
		}
		// printf("\n");
	}
	int sum = 0;
	for(int i = 1; i <= 1005; ++i) {
		sum += x[i]*x[i];
	}
	printf("%d\n", sum);
}