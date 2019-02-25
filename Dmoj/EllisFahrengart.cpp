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

const int N = 1e5+5;

class EllisFahrengart {
private:
    int n, m, sz;
    int A[N];
    long t1[N], t2[N], ans[N];
    vector<iii> block[320];
    vi coor;
    void update(int x, int v) {
        for(int i = x; i <= n; i += i & -i) t1[i] += v;
    }
    long query(int x, long v = 0) {
        for(int i = x; i; i -= i & -i) v += t1[i];
        return v;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> A[i], coor.emplace_back(A[i]);
        sort(all(coor));
        coor.resize(unique(all(coor)) - coor.begin());
        for(int i = 1; i <= n; ++i) A[i] = upper_bound(all(coor), A[i]) - coor.begin();
        cin >> m;
        sz = 317;
        for(int i = 0, a, b; i < m; ++i) {
            cin >> a >> b;
            block[a/sz].emplace_back(a, b, i);
        }
        for(int i = 0; i < sz; ++i) {
            sort(all(block[i]), [&](const iii &a, const iii &b) { return get<1>(a) < get<1>(b); });
            memset(t1, 0, sizeof t1), memset(t2, 0, sizeof t2);
            int l = sz * i, r = sz * i;
            long sum = 0;
            if(!i) l++, r++;
            for(auto v : block[i]) {
                int x, y, p; tie(x, y, p) = v;
                while(r <= y) {
                    sum += r - l - query(A[r]);
                    update(A[r], 1);
                    r++;
                }
                while(l > x) {
                    --l;
                    sum += query(A[l]-1);
                    update(A[l], 1);
                }
                while(l < x) {
                    sum -= query(A[l]-1);
                    update(A[l], -1);
                    l++;
                }
                ans[p] = sum;
            }
        }
        for(int i = 0; i < m; ++i) cout << ans[i] << endl;
    }
};