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

const int N = 1<<16;

class cbs {
private:
    int n, m, ans;
    char inp[N];
    int pref[11][N];
    map<int, int> pos[11];
    int f(int x) { return x + (N<<2); }
    struct item {
        int val;
        item *l, *r;
        item(int val, item *l, item *r) : val(val), l(l), r(r) {}
    };
    item *ver[N];
    item *newpar(item *l, item *r) { return new item(0, l, r); }
    item *newson(int val) { return new item(val, nullptr, nullptr); }
    item *build(int l = 1, int r = (N<<3)) {
        if(l == r) return newson(0);
        int mid = l + r >> 1;
        return newpar(build(l, mid), build(mid+1, r));
    }
    item *update(int x, item *p, int l = 1, int r = (N<<3)) {
        if(l == r) return newson(p->val+1);
        int mid = l + r >> 1;
        if(x <= mid) return newpar(update(x, p->l, l, mid), p->r);
        else return newpar(p->l, update(x, p->r, mid+1, r));
    }
    int query(int x, item *p, int l = 1, int r = (N<<3)) {
        if(l == r) return p->val;
        int mid = l + r >> 1;
        if(x <= mid) return query(x, p->l, l, mid);
        else return query(x, p->r, mid+1, r);
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
            cin >> inp+1;
            for(int j = 1; j <= m; ++j)
                pref[i][j] = pref[i][j-1] + (inp[j] == '(' ? 1 : -1);
        }
        ver[0] = build();
        for(int j = 1; j <= m; ++j) {
            int mx = 0, sum = 0;
            for(int i = 1; i <= n; ++i) {
                mx = max(mx, pos[i][pref[i][j]-1]);
                pos[i][pref[i][j]] = j;
                sum += pref[i][j];
            }
            ans += query(f(sum), ver[j-1]) - query(f(sum), ver[mx]);
            ver[j] = update(f(sum), ver[j-1]);
        }
        cout << ans << endl;
    }
};
