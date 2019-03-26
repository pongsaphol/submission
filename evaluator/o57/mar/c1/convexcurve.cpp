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

const int N = 5005;

class convexcurve {
private:
    int n, ans;
    int inp[N];
    double* dp[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> inp[i], dp[i] = new double[i+1], fill_n(dp[i], i+1, -INF), dp[i][1] = INF;
        for(int i = 2; i <= n; ++i) for(int j = 1; j < i; ++j) {
            double now = (double)(inp[i] - inp[j]) / (i - j);
            int l = 1, r = j;
            while(l < r) {
                int m = l + r + 1 >> 1;
                if(dp[j][m] >= now) l = m;
                else r = m-1;
            }
            dp[i][l+1] = max(dp[i][l+1], now);
            ans = max(ans, l+1);
        }
        cout << ans << endl;
    }
};