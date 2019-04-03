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

const int N = 405;

class snakes {
private:
    int n, k;
    long inp[N], dp[N][N];
    long ans;
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k;
        fill_n(dp[0], N*N, LINF);
        for(int i = 1; i <= n; ++i) cin >> inp[i], ans -= inp[i];
        for(long i = 1, mx = 0; i <= n; ++i) {
            mx = max(mx, inp[i]);
            dp[0][i] = mx * i;
        }
        for(int i = 1; i <= k; ++i) {
            for(int j = i+1; j <= n; ++j) {
                for(long z = j-1, mx = inp[j]; z >= i; --z) {
                    dp[i][j] = min(dp[i][j], dp[i-1][z] + mx * (j-z));
                    mx = max(mx, inp[z]);
                }
            }
        }
        cout << dp[k][n] + ans << endl;
    }
};