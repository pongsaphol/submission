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

const int N = 1e3+5;

class TaskB {
private:
    int n, k;
    char inp[N];
    int ori[N], f1[N], f2[N];
    long dp[2][N][N];
    long cnt[2][N][N];
    long get(int f[], int k) {
        memset(dp, 0, sizeof dp);
        memset(cnt, 0, sizeof cnt);
        dp[0][0][0] = 1;
        cnt[0][0][0] = 1;
        for(int i = 0; i <= k; ++i) for(int j = i+1; j < n; ++j) {
            long val = ori[j] ^ (i&1);
            cnt[0][i][j] = (cnt[0][i][j-1] + (i ? cnt[0][i-1][j-1] : 0)) % MOD;
            cnt[1][i][j] = (cnt[1][i][j-1] + (i ? cnt[1][i-1][j-1] : 0)) % MOD;
            dp[0][i][j] = ((dp[0][i][j-1] + (i ? dp[0][i-1][j-1] : 0)) * 2 + val * cnt[0][i][j]) % MOD;
            dp[1][i][j] = ((dp[1][i][j-1] + (i ? dp[1][i-1][j-1] : 0)) * 2 + val * cnt[1][i][j]) % MOD;
            if(f[j] == 1 && val == 0) {
                cnt[1][i][j] = (cnt[1][i][j] + cnt[0][i][j]) % MOD;
                dp[1][i][j] = (dp[1][i][j] + dp[0][i][j]) % MOD;
            }
            if(f[j] != val) dp[0][i][j] = cnt[0][i][j] = 0;
        }
        return (dp[0][k][n-1] + dp[1][k][n-1]) % MOD;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k;
        cin >> inp;
        for(int i = 1; i < n; ++i) ori[i] = inp[i-1] == 'L' ? 1 : 0;
        cin >> inp;
        for(int i = n-1; ~i; --i) {
            if(inp[i] == '1') {
                inp[i] = '0';
                break;
            } else inp[i] = '1';
        }
        for(int i = 0; i < n; ++i) f1[i] = inp[i] == '1' ? 1 : 0;
        cin >> inp;
        for(int i = 0; i < n; ++i) f2[i] = inp[i] == '1' ? 1 : 0;
        long val = get(f2, k) - (f1[0] ? get(f1, k) : 0);
        if(k) val += get(f2, k-1) - (f1[0] ? get(f1, k-1) : 0);
        for(int i = 0; i < n; ++i) ori[i] ^= 1;
        val += get(f2, k) - (f1[0] ? get(f1, k) : 0);
        if(k) val += get(f2, k-1) - (f1[0] ? get(f1, k-1) : 0);
        val = ((val % MOD) + MOD) % MOD;
        cout << val << endl;
    }
};