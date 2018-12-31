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

const int N = 1e6+1;
const long M = 998244353;

class TaskD {
private:
    long n;
    long ans = 0;
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        if(n == 1) {
            cout << 1 << endl;
            return;
        }
        long ret = 1;
        for(long i = n; i > 2; --i) {
            ret = ret * i % M;
            ans = ans - ret + M;
            ans %= M;
        }
        ret *= 2;
        ret %= M;
        ans += (n-1)* ret;
        ans %= M;
        cout << ans << endl;
    }
};