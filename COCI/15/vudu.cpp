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

const int N = 1e6+5;

class vudu {
private:
    int n, p, A[N];
    int t[N];
    long pref[N], ans;
    vector<long> coor;
    void update(int x) {
        for(int i = x+1; i < N; i += i & -i) t[i-1]++;
    }
    int query(int x, int v = 0) {
        for(int i = x+1; i; i -= i & -i) v += t[i-1];
        return v;
    }
    int get(long x) { return upper_bound(all(coor), x) - coor.begin() - 1; }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> A[i];
        cin >> p;
        for(int i = 1; i <= n; ++i) {
            pref[i] = pref[i-1] + A[i] - p;
            coor.emplace_back(pref[i]);
        }
        coor.emplace_back(0);
        sort(all(coor));
        coor.resize(unique(all(coor)) - coor.begin());
        update(get(0));
        for(int i = 1; i <= n; ++i) {
            ans += query(get(pref[i]));
            update(get(pref[i]));
        }
        cout << ans << endl;
    }
};