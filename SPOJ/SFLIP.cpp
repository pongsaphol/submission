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

const int N = 1<<17;

#define var int p = 1, int l = 1, int r = n
#define mid (l + r >> 1)
#define lb p<<1, l, mid
#define rb p<<1|1, mid+1, r

int n, k;

class SFLIP {
private:
    struct node {
        pii l, r;
        iii m;
        int sum;
        node() : l(INF, -1), r(INF, -1), m(INF, -1, -1), sum(0) {}
        node(int x, int pos) : l(x, pos), r(x, pos), m(x, pos, pos), sum(x) {} 
        friend inline node operator+(const node &a, const node &b) {
            node z;
            z.l = a.l, z.r = b.r;
            if(a.sum + b.l.x < z.l.x) z.l = b.l, z.l.x += a.sum;
            if(b.sum + a.r.x < z.r.x) z.r = a.r, z.r.x += b.sum; 
            if(get<0>(a.m) < get<0>(b.m)) z.m = a.m; else z.m = b.m;
            if(a.r.x + b.l.x < get<0>(z.m)) z.m = iii(a.r.x + b.l.x, a.r.y, b.l.y);
            z.sum = a.sum + b.sum;
            return z;
        }
    };
    struct data {
        node a, b;
        bool lazy;
        data() {}
        data(node a, node b) : a(a), b(b), lazy(false) {}
        friend inline data operator+(const data &a, const data &b) {
            data ret;
            ret.a = a.a + b.a, ret.b = a.b + b.b;
            return ret;
        }
    } t[N<<1];
    int inp[N];
    void build(var) {
        if(l == r) return void(t[p] = data(node(inp[l], l), node(-inp[r], r)));
        build(lb), build(rb);
        t[p] = t[p<<1] + t[p<<1|1];
    }
    void push(var) {
        if(!t[p].lazy) return;
        swap(t[p].a, t[p].b);
        if(l != r) t[p<<1].lazy ^= 1, t[p<<1|1].lazy ^= 1;  
        t[p].lazy ^= 1;
    }
    void update(int x, int y, var) {
        push(p, l, r);
        if(x > r || l > y) return; 
        if(x <= l && r <= y) {
            t[p].lazy ^= 1; 
            push(p, l, r);
            return;
        }
        update(x, y, lb), update(x, y, rb);
        t[p] = t[p<<1] + t[p<<1|1];
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> inp[i];
        build();
        while(k--) {
            if(get<0>(t[1].a.m) >= 0) break;
            int l = get<1>(t[1].a.m), r = get<2>(t[1].a.m);
            update(l, r);
        }        
        cout << t[1].a.sum << endl;
    }
};