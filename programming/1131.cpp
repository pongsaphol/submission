#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+5;
const int mod = 2553;

int dp[MAXN][4][4];
char arr[MAXN];

int main() {
    freopen("r", "r", stdin);
    int n;
    scanf("%d", &n);
    scanf("%s", arr + 1);
    for(int i = 1; i <= n; ++i) {
        if(arr[i] == 'P') arr[i] = 1;
        if(arr[i] == 'R') arr[i] = 2;
        if(arr[i] == 'S') arr[i] = 3;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= 3; ++j) {
            for(int k = 0; k <= 3; ++k) {
                for(int l = 1; l <= 3; ++l) {
                    if(j == 1 && l == 1) continue;
                    if(j == 0) dp[i][k][l] = 0;
                    dp[i][k][l] += dp[i-1][j][k];
                    dp[i][l][j] %= mod;
                }
            }
        }
        for(int j = 1; j < arr[i]; ++j) {
            if(i == 1 ||!(arr[i-2] == arr[i-1] && arr[i-1] == j)) dp[i][arr[i-1]][j]++;
        }
    }
    int ans = 1;
    for(int i = 0; i <= 3; ++i) {
        for(int j = 0; j <= 3; ++j) {
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    printf("%d\n", ans);
}
