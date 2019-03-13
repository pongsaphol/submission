#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e6+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 1e4+5;

class calvinball {
private:
    int n;
    int inp[N];
    int dp[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> inp[i];
        int mx = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j; --j) dp[j] = (dp[j-1] + 1ll * dp[j] * j) % MOD;
            dp[mx] += inp[i]-1;
            mx = max(mx, inp[i]);
        }
        int sum = 1;
        for(int i = 1; i <= n; ++i) sum = (sum + dp[i]) % MOD;
        cout << sum << endl;
    }
};