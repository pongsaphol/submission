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


class TaskD {
private:
    long n;
    int m;
    vector<vector<int> > mul(const vector<vector<int> > &a, const vector<vector<int> > &b) {
        vector<vector<int> > ret(m, vector<int>(m));
        for(int i = 0; i < m; ++i) for(int j = 0; j < m; ++j) {
            for(int k = 0; k < m; ++k) ret[i][j] = (ret[i][j] + 1ll * a[i][k] * b[k][j]) % MOD;
        }
        return ret;
    }
    vector<vector<int> > dp[64];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        vector<vector<int> > matrix(m, vector<int>(m));
        for(int i = 1; i < m; ++i) matrix[i-1][i] = 1;
        matrix[m-1][0] = matrix[m-1][m-1] = 1;
        dp[0] = matrix;
        for(int i = 1; i < 63; ++i) dp[i] = mul(dp[i-1], dp[i-1]);
        vector<vector<int> > iden(m, vector<int>(m));
        for(int i = 0; i < m; ++i) iden[i][i] = 1;
        for(int i = 0; i < 63; ++i) if(n >> i & 1) iden = mul(iden, dp[i]);
        long ans = 0;
        for(int i = 0; i < m; ++i) ans = (ans + iden[0][i]) % MOD;
        cout << ans << endl;
    }
};