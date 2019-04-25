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


class TaskC {
private:
    long n, m;
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        long z;
        long ft, se;
        cin >> ft >> se;
        z = ft;
        long g = se - ft;
        ft = se;
        for(int i = 3; i <= n; ++i) {
            cin >> se;
            g = __gcd(g, se - ft);
            ft = se;
        }
        for(int i = 1; i <= m; ++i) {
            long val;
            cin >> val;
            if(g % val == 0) {
                cout << "YES" << endl;
                cout << z << ' ' << i << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
};