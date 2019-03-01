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

class TaskK {
private:
    struct item {
        long key, lazy;
        int pos, prio;
        item *l, *r;
        item(long key, int pos) : key(key), pos(pos), prio(rand()), lazy(0), l(nullptr), r(nullptr) {}
    };
    using pitem = item*;
    void push(pitem t) {
        if(t) if(t->lazy) {
            t->key += t->lazy;
            if(t->l) t->l->lazy += t->lazy;
            if(t->r) t->r->lazy += t->lazy;
            t->lazy = 0;
        }
    }
    void split(pitem t, long key, pitem &l, pitem &r) {
        push(t);
        if(!t) l = r = nullptr;
        else if(key < t->key) split(t->l, key, l, t->l), r = t;
        else split(t->r, key, t->r, r), l = t;
    }
    void merge(pitem &t, pitem l, pitem r) {
        push(l), push(r);
        if(!l || !r) t = l ? l : r;
        else if(l->prio > r->prio) merge(l->r, l->r, r), t = l;
        else merge(r->l, l, r->l), t = r;
    }
    void insert(pitem &t, pitem it) {
        push(t);
        if(!t) t = it;
        else if(it->prio > t->prio) split(t, it->key, it->l, it->r), t = it;
        else insert(it->key < t->key ? t->l : t->r, it);
    }
    int n, m;
    pitem t, t1, t2;
    void travel(pitem it, int val) {
        if(!it) return;
        push(it);
        travel(it->l, val), travel(it->r, val);
        it->l = it->r = nullptr;
        it->key += val;
        insert(t, it);
    }
    long ans[N];
    void print(pitem t) {
        if(!t) return;
        push(t);
        print(t->l), print(t->r);
        ans[t->pos] = t->key;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 0, val; i < n; ++i) {
            cin >> val;
            insert(t, new item(val, i));
        }
        for(int i = 0, z, a, b; i < m; ++i) {
            cin >> z >> a >> b;
            split(t, a, t1, t2);
            if(z == 1) {
                if(b >= 0) {
                    if(t1) t1->lazy -= b;
                    merge(t, t1, t2);
                } else {
                    t = t2;
                    travel(t1, -b);
                }
            } else {
                if(b >= 0) {
                    if(t2) t2->lazy += b;
                    merge(t, t1, t2);
                } else {
                    t = t1;
                    travel(t2, b);
                }
            }
        }
        print(t);
        for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
        cout << endl;
    }
};