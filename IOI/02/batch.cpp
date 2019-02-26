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

const int N = 1e4+5;

class batch {
private:
    int n, s;
    int t[N], f[N];
    long dp[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> s;
        for(int i = 1; i <= n; ++i) cin >> t[i] >> f[i], t[i] += t[i-1], f[i] += f[i-1];
        fill_n(dp, N, LINF);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) dp[i] = min(dp[i], dp[j] + (s + t[i] - t[j]) * (f[n] - f[j]));
        }
        cout << dp[n] << endl;
    }
};