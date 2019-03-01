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
const int INF = 2e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};


class GSS6 {
private:
    struct item {
        int val, sum, cnt, prio;
        int lb, rb, mb;
        item *l, *r;
        item(int val) : val(val), sum(val), cnt(1), prio(rand()), lb(val), rb(val), mb(val), l(nullptr), r(nullptr) {}
    };
    using pitem = item*;
    int gl(pitem t) { return t ? t->lb : -INF; }
    int gr(pitem t) { return t ? t->rb : -INF; }
    int gm(pitem t) { return t ? t->mb : -INF; }
    int gs(pitem t) { return t ? t->sum : 0; }
    int cnt(pitem t) { return t ? t->cnt : 0; }
    void upd(pitem t) {
        if(!t) return;
        t->lb = max({gl(t->l), gs(t->l) + t->val + max(0, gl(t->r))});
        t->rb = max({gr(t->r), gs(t->r) + t->val + max(0, gr(t->l))});
        t->mb = max({gm(t->l), gm(t->r), max(0, gr(t->l)) + t->val + max(0, gl(t->r))});
        t->sum = t->val + gs(t->l) + gs(t->r);
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
    }
    void split(pitem t, int key, pitem &l, pitem &r) {
        if(!t) l = r = nullptr;
        else if(key <= cnt(t->l)) split(t->l, key, l, t->l), r = t;
        else split(t->r, key - cnt(t->l) - 1, t->r, r), l = t;
        upd(t);
    }
    void merge(pitem &t, pitem l, pitem r) {
        if(!l || !r) t = l ? l : r;
        else if(l->prio > r ->prio) merge(l->r, l->r, r), t = l;
        else merge(r->l, l, r->l), t = r;
        upd(t);
    }
    int n, m;
    pitem t;
    pitem t1, t2, t3;
public:
    void solve(istream& cin, ostream& cout) {
        srand(time(nullptr));
        cin >> n;
        for(int i = 0, val; i < n; ++i) {
            cin >> val;
            merge(t, t, new item(val));
        }
        cin >> m;
        for(int i = 0, a, b; i < m; ++i) {
            char c;
            cin >> c >> a;
            if(c == 'I') {
                cin >> b;
                split(t, a-1, t1, t2);
                merge(t, t1, new item(b));
                merge(t, t, t2);
            } if(c == 'D') {
                split(t, a-1, t1, t2);
                split(t2, 1, t2, t3);
                delete t2;
                merge(t, t1, t3);
            } if(c == 'R') {
                cin >> b;
                split(t, a-1, t1, t2);
                split(t2, 1, t2, t3);
                delete t2;
                merge(t, t1, new item(b));
                merge(t, t, t3);
            } if(c == 'Q') {
                cin >> b;
                split(t, a-1, t1, t2);
                split(t2, b-a+1, t2, t3);
                cout << t2->mb << endl;
                merge(t, t1, t2);
                merge(t, t, t3);
            }
        }
    }
};