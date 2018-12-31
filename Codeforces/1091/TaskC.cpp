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
    int n;
    set<long> ans;
    void f(int k) {
        long val = (2+n-k);
        val *= n;
        val /= 2;
        val /= k;
        ans.emplace(val);
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i * i <= n; ++i) {
            if(n % i == 0) f(i), f(n/i);
        }
        for(auto x : ans) cout << x << ' ';
        cout << endl;
    }
};