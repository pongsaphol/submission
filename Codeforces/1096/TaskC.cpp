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


class TaskC {
private:
    int T;
    int ans[200];
public:
    void solve(istream& cin, ostream& cout) {
        for(int i = 3; i <= 400; ++i) {
            for(int j = 1; j <= i-2; ++j) {
                if((180 * j) % i == 0) {
                    int now = 180 * j / i;
                    if(!ans[now]) ans[now] = i;
                }
            }
        }
        cin >> T;
        while(T--) {
            int ang; cin >> ang;
            if(ans[ang]) cout << ans[ang] << endl;
            else cout << -1 << endl;
        }
    }
};