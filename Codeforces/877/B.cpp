#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <cstring>
#include <iterator>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 5e3+5;

char A[MAXN];
int dp[2][MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
	scanf("%s", A+1);
	int len = strlen(A+1);
	for(int i = 1; i <= len; ++i) {
		if(A[i] == 'a') dp[0][i] += dp[0][i-1] + 1, dp[1][i] = dp[1][i-1];
		else dp[1][i] += dp[1][i-1] + 1, dp[0][i] = dp[0][i-1];
	}
	int mx = 0;
	for(int i = 0; i <= len; ++i) {
		for(int j = i+1; j <= len; ++j) {
			mx = max(mx, dp[0][len] - dp[0][j] + dp[1][j] - dp[1][i] + dp[0][i]);
		}
	}
	return !printf("%d\n", mx);
}