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

const int N = 2e3+5;

class strah {
private:
    int n, m;
    int dp[N][N];
    char inp[N][N];
    long f(long x) { return x * (x+1) / 2; }
    long ans;
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) cin >> inp[i]+1;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) dp[i][j] = inp[i][j] == '#' ? 0 : (dp[i-1][j]+1);
        for(int i = 1; i <= n; ++i) {
            dp[i][0] = -1;
            stack<int> stk;
            stk.emplace(0);
            long sum = 0, ret = 0;
            for(int j = 1; j <= m; ++j) {
                sum += ret;
                while(!stk.empty() && dp[i][stk.top()] >= dp[i][j]) {
                    int v = stk.top(); stk.pop();
                    long z = f(dp[i][v]) * (v - stk.top());
                    ret -= z, sum -= z * (j - v);
                    sum -= f(dp[i][v]) * f(v - stk.top());
                }
                sum += f(dp[i][j]) * f(j - stk.top());
                ret += f(dp[i][j]) * (j - stk.top());
                stk.emplace(j);
                ans += sum;
            }
        }
        cout << ans << endl;
    }
};