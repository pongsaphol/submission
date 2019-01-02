#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
#define iii tuple<long, long, long>
#define vi vector<long>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 1<<17;

int n, q;
#define var int p = 1, int l = 1, int r = n
#define mid (l + r >> 1)
#define lb p<<1, l, mid
#define rb p<<1|1, mid+1, r

class TaskE {
private:
    struct data {
        vi t, m, r;
    } t[N<<1];
    long S[N], M[N], R[N], lz[N<<1];
    void build(var) {
        t[p].m.emplace_back(0), t[p].r.emplace_back(0);
        vector<iii> vec;
        for(int i = l; i <= r; ++i) {
            if(R[i]) vec.emplace_back(M[i] / R[i], M[i], R[i]);
            else vec.emplace_back(INF, M[i], R[i]);
        }
        sort(all(vec));
        for(auto &x : vec) {
            t[p].t.emplace_back(get<0>(x));
            t[p].m.emplace_back(t[p].m.back() + get<1>(x));
            t[p].r.emplace_back(t[p].r.back() + get<2>(x));
        }
        t[p].t.emplace_back(INF);
        if(l != r) build(lb), build(rb);
    }
    long query(int x, int y, long tt, var) {
        if(~lz[p] && l != r) lz[p<<1] = lz[p<<1|1] = lz[p];
        if(x > r || l > y) return 0;
        if(l == r && lz[p] == 0) {
            lz[p] = tt;
            return min(M[l], S[l] + tt * R[l]);
        }
        if(x <= l && r <= y) {
            if(lz[p] == -1 || lz[p] == 0) {
                lz[p] = tt;
                return query(x, y, tt, lb) + query(x, y, tt, rb);
            }
            int z = lower_bound(all(t[p].t), tt - lz[p]) - t[p].t.begin();
            long val = t[p].m[z] + (t[p].r.back() - t[p].r[z]) * (tt - lz[p]);
            lz[p] = tt;
            return val;
        }
        lz[p] = -1;
        return query(x, y, tt, lb) + query(x, y, tt, rb);
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> S[i] >> M[i] >> R[i];
        build();
        cin >> q;
        for(int i = 0, tt, l, r; i < q; ++i) {
            cin >> tt >> l >> r;
            cout << query(l, r, tt) << endl;
        }
    }
};