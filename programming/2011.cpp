#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+5;

char arr[MAXN];
int n,m,dp[MAXN][4][4];

void read_input() {
	scanf("%d%d", &n, &m);
	scanf("%s", arr + 1);
	for(int i = 1; i <= n; ++i) {
		if(arr[i] == 'L') arr[i] = 1;
		else arr[i] = 2;
	}
}

int solve() {
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= 2; ++j) {
			for(int k = 0; k <= 2; ++k) {
				for(int l = 1; l <= 2; ++l) {
					if(j == 0) dp[i][k][l] = 0;
					dp[i][k][l] += dp[i-1][j][k];
					//dp[i][j][l] %= m;
				}
			}
		}
		for(int j = 1; j < arr[i]; ++j) {
			if(i == 1 ||!(arr[i-2] == arr[i-1] && arr[i-1] == j)) dp[i][arr[i-1]][j]++;
		}
	}
	int ans = 0;
	for(int i = 0; i <= 2; ++i) {
        for(int j = 0; j <= 2; ++j) {
            ans += dp[n][i][j];
            //ans %= m;
        }
    }
    return ans;
}

int main() {
	freopen("r", "r", stdin);
	read_input();
	printf("%d\n", solve());
}
