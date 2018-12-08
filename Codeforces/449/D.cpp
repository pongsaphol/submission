/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author win11905
 */

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

const int N = 1<<20;

class TaskD {
private:
    int n;
    int t2[N], dp[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 0, val; i < n; ++i) cin >> val, dp[val]++;
        t2[0] = 1;
        for(int i = 1; i < N; ++i) t2[i] = (t2[i-1] << 1) % MOD;
        for(int i = 0; i < 20; ++i) for(int j = 0; j < N; ++j) {
            if(!(j >> i & 1)) dp[j] += dp[(1 << i) | j];
        }
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            bool st = true;
            for(int j = 0; j < 20; ++j) if(i >> j & 1) st ^= 1;
            ans = (ans + (st ? 1 : -1) * t2[dp[i]]) % MOD;
        }
        cout << (ans + MOD) % MOD << endl;
    }
};

class Solver {
public:
    void solve(std::istream& in, std::ostream& out) {
        TaskD *obj = new TaskD();
        obj->solve(in, out);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solver solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}