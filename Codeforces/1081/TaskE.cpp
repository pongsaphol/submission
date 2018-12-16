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

const int N = 2e5+5;

class TaskE {
private:
    int n;
    long pref[N];
    long ans[N];
    int ptr[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i < N; ++i) pref[i] = pref[i-1] + 2*i-1;
        for(int i = 2; i <= n; i += 2) {
            cin >> ans[i];
            for(int j = ptr[i-2]+1; j <= N; ++j) {
                if(j == N) {
                    cout << "No" << endl;
                    return;
                }
                if(ans[i] > pref[j]) continue;
                long z = *lower_bound(pref+ptr[i-2]+1, pref+j, pref[j] - ans[i]);
                if(pref[j] - z == ans[i]) {
                    ans[i-1] = z - pref[ptr[i-2]];
                    ptr[i] = j;
                    break;
                }
            }
        }
        cout << "Yes" << endl;
        for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << endl;
    }
};