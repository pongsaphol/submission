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

class TaskB {
private:
    int n, val[N];
    queue<int> Q[N];
    int ans[N];
    bool check[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> val[i];
            Q[val[i]].emplace(i);
        }
        int step = 1;
        for(int i = 1; i <= n; ++i) {
            if(check[i]) continue;
            int want = n - val[i];
            while(want--) {
                if(Q[val[i]].empty()) {
                    cout << "Impossible" << endl;
                    return;
                }
                check[Q[val[i]].front()] = true;
                ans[Q[val[i]].front()] = step;
                Q[val[i]].pop();
            }
            step++;
        }
        cout << "Possible" << endl;
        for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << endl;
    }
};