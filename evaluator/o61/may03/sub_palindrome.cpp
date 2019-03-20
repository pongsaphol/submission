#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int>
#define long long long
#define pii pair<long, long>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 1<<17;

int n, m;
pii iden(131ll, 133ll);

class sub_palindrome {
private:
    char str[N];
    pii preh[N], posh[N], H[N] = {pii(1, 1)};
    pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
    pii sub(pii a, pii b) { return pii(a.x - b.x, a.y - b.y); }
    pii mul(pii a, pii b) { return pii(a.x * b.x, a.y * b.y); }
    int d[4][N];
    void solve_dp() {
        for(int i = 1; i <= n; ++i) {
            preh[i] = add(mul(preh[i-1], iden), pii(str[i], str[i]));
            H[i] = mul(H[i-1], iden);
        }
        for(int i = n; i; --i)
            posh[i] = add(mul(posh[i+1], iden), pii(str[i], str[i]));
        for(int i = 1; i <= n; ++i) {
            int l = 1, r = min(i, n-i+1);
            while(l < r) {
                int m = l + r + 1 >> 1;
                int x = i-m+1, y = i+m-1;
                pii hl = sub(preh[y], mul(preh[x-1], H[y-x+1]));
                pii hr = sub(posh[x], mul(posh[y+1], H[y-x+1]));
                if(hl == hr) l = m;
                else r = m-1;
            }
            d[0][i] = l-i, d[1][i] = l+i;
            l = 0, r = min(i, n-i);
            while(l < r) {
                int m = l + r + 1 >> 1;
                int x = i-m+1, y = i+m;
                pii hl = sub(preh[y], mul(preh[x-1], H[y-x+1]));
                pii hr = sub(posh[x], mul(posh[y+1], H[y-x+1]));
                if(hl == hr) l = m;
                else r = m-1;
            }
            d[2][i] = l-i, d[3][i] = l+i;
        }
    }
    struct data {
        long sum;
        int cnt;
        data *l, *r;
        data() {}
        data(long sum, int cnt, data *l, data *r) : sum(sum), cnt(cnt), l(l), r(r) {}
    };
    data *newson(long sum, int cnt) { return new data(sum, cnt, nullptr, nullptr); }
    data *newpar(data *l, data *r) { return new data(l->sum + r->sum, l->cnt + r->cnt, l, r); }
    data *build(int l, int r) {
        if(l == r) return newson(0, 0);
        int m = l + r >> 1;
        return newpar(build(l, m), build(m+1, r));
    }
    data *update(int x, long v, data *p, int l, int r) {
        if(l == r) return newson(p->sum + v, p->cnt + 1);
        int m = l + r >> 1;
        if(x <= m) return newpar(update(x, v, p->l, l, m), p->r);
        else return newpar(p->l, update(x, v, p->r, m+1, r));
    }
    pii query(int x, int p, data *p1, data *p2, int l, int r) {
        if(l == r) return pii(p2->sum - p1->sum, p2->cnt - p1->cnt);
        int m = l + r >> 1;
        if(coor[p][m] >= x) return add(query(x, p, p1->l, p2->l, l, m), pii(p2->r->sum - p1->r->sum, p2->r->cnt - p1->r->cnt));
        return query(x, p, p1->r, p2->r, m+1, r);
    }
    data *ver[4][N];
    vi coor[4];
    void solve_persist() {
        for(int i = 0; i < 4; ++i) coor[i].emplace_back(-INF), coor[i].emplace_back(INF);
        for(int j = 0; j < 4; ++j) for(int i = 1; i <= n; ++i) coor[j].emplace_back(d[j][i]);
        for(int i = 0; i < 4; ++i) sort(all(coor[i])), coor[i].resize(unique(all(coor[i])) - coor[i].begin());
        for(int i = 0; i < 4; ++i) ver[i][0] = build(1, coor[i].size()-1);
        for(int j = 0; j < 4; ++j) for(int i = 1; i <= n; ++i)
            ver[j][i] = update(lower_bound(all(coor[j]), d[j][i]) - coor[j].begin(), d[j][i], ver[j][i-1], 1, coor[j].size()-1);
    }
    long f(int v, int t, int l, int r, long inv) {
        pii n1 = query(v, t, ver[t][l-1], ver[t][r], 1, coor[t].size()-1);
        pii n2 = pii(ver[t][r]->sum - ver[t][l-1]->sum, ver[t][r]->cnt - ver[t][l-1]->cnt);
        return n1.y * v + n2.x - n1.x + (inv * (r-l+1) * (l + r)) / 2;
    }
    long get_answer(int l, int r) {
        int m1 = (l + r) >> 1, m2 = (l + r - 1) >> 1;
        return f(1-l, 0, l, m1, 1) + f(r+1, 1, m1+1, r, -1) + f(1-l, 2, l, m2, 1) + f(r, 3, m2+1, r-1, -1);
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> str + 1;
        solve_dp();
        solve_persist();
        cin >> m;
        for(int i = 0, l, r; i < m; ++i) {
            cin >> l >> r;
            cout << get_answer(l, r) << endl;
        }
    }
};