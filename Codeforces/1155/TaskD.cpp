#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 3e5+5;

class TaskD {
private:
    long n, m, A[N], ans;
    long dp[3][N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) cin >> A[i];
        for(int i = 1; i <= n; ++i) dp[0][i] = max(dp[0][i-1], 0ll) + A[i];
        for(int i = n; i >= 1; --i) dp[1][i] = max(dp[1][i+1], 0ll) + A[i];
        for(int i = 1; i <= n; ++i) dp[2][i] = dp[2][i-1] + A[i] * m;
        long mn = *max_element(dp[0], dp[0]+N);
        for(int i = 1; i <= n; ++i) {
            ans = max(ans, dp[2][i] + max(0ll, dp[1][i+1]) - mn);
            mn = min(mn, dp[2][i] - max(0ll, dp[0][i]));
        }
        cout << ans << endl;
    }
};