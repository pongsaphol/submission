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

const int N = 1e5+5;
char ent[] = "_hard";

class TaskD {
private:
    int n;
    char A[N];
    long num[N];
    long dp[N][5];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        cin >> A + 1;
        dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = LINF;
        for(int i = 1; i <= n; ++i) {
            cin >> num[i];
            for(int j = 0; j <= 4; ++j) dp[i][j] = dp[i-1][j];
            for(int j = 1; j <= 4; ++j) if(A[i] == ent[j]) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j-1] = dp[i-1][j-1] + num[i];
            }
        }
        long ans = LINF;
        for(int i = 0; i < 4; ++i) ans = min(ans, dp[n][i]);
        cout << ans << endl;
    }

};