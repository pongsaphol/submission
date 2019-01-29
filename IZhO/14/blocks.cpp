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

const int N = 1e5+5;
const int K = 1e2+5;

class blocks {
private:
    int n, k;
    int dp[K][N];
    int A[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> A[i];
        for(int i = 1; i <= n; ++i) dp[1][i] = max(dp[1][i-1], A[i]);
        for(int i = 2; i <= k; ++i) {
            stack<iii> stk;
            for(int j = i; j <= n; ++j) {
                int mn = dp[i-1][j-1];
                while(!stk.empty() && get<0>(stk.top()) <= A[j]) mn = min(mn, get<1>(stk.top())), stk.pop();
                stk.emplace(A[j], mn, min(mn + A[j], stk.empty() ? INF : get<2>(stk.top())));
                dp[i][j] = get<2>(stk.top());
            }
        }
        cout << dp[k][n] << endl;
    }
};