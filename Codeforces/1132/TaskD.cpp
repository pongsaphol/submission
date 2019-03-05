#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int>
#define long long long
#define pii pair<long, long>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e12+1;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 2e5+5;

class TaskD {
private:
    int n, m;
    long z[N], d[N];
    long s[N];
    bool f(long mid) {
        priority_queue<pii, vector<pii>, greater<pii>> Q;
        for(int i = 1; i <= n; ++i) Q.emplace(z[i] / d[i], i), s[i] = z[i];
        for(int i = 0; i < m; ++i) {
            auto u = Q.top(); Q.pop();
            if(u.x < i) return false;
            s[u.y] += mid;
            Q.emplace(s[u.y] / d[u.y], u.y);
        }
        return true;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) cin >> z[i];
        for(int i = 1; i <= n; ++i) cin >> d[i];
        long l = 0, r = LINF;
        while(l < r) {
            long m = l + r >> 1;
            if(f(m)) r = m;
            else l = m+1;
        }
        cout << (r == LINF ? -1 : r) << endl;
    }
};2 4
3 2
4 2

