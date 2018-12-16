#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 2005;
const int M = 998244353;

class TaskC {
private:
    int n, m, k;
    long dp[N][N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m >> k;
        k++;
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i) dp[0][i] = 1;
        for(int i = 1; i <= k; ++i) {
            for(int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1] * (i == 1 ? m : m-1);
                dp[i][j] %= M;
            }
        }
        cout << ((dp[k][n] - dp[k][n-1] + M) % M) << endl;
    }
};