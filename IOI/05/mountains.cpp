#include <bits/stdc++.h>
#define long long long
#define pii pair<long, long>
#define x first
#define y second
#define all(x) x.begin(), x.end()
#define iiii tuple<int, int, int, int>
using namespace std;

const int N = 1<<18;
const long INF = 1e12;

int n;
long t[N<<1], ts[N<<1], lz[N<<1], val[N<<1];

vector<iiii> vec;
vector<int> coor;

void push(int p, int l, int r) {
    if(lz[p] == INF) return;
    val[p] = lz[p];
    ts[p] = (coor[r] - coor[l-1]) * lz[p];
    t[p] = lz[p] <= 0 ? 0 : ts[p];
    if(l != r) lz[p<<1] = lz[p<<1|1] = lz[p];
    lz[p] = INF;
}

void update(int x, int y, int v, int p = 1, int l = 0, int r = coor.size()-1) {
    push(p, l, r);
    if(x > r || l > y) return;
    if(x <= l && r <= y) {
        lz[p] = v;
        return push(p, l, r);
    }
    int m = (l + r) / 2;
    update(x, y, v, p << 1, l, m), update(x, y, v, p<<1|1, m+1, r);
    ts[p] = ts[p<<1] + ts[p<<1|1];
    t[p] = max(t[p<<1], ts[p<<1] + t[p<<1|1]);
}

pii query(int y, int p = 1, int l = 0, int r = coor.size()-1) {
    push(p, l, r);
    if(r == y) return pii(t[p], ts[p]);
    int m = (l + r) / 2;
    push(p<<1, l, m), push(p<<1|1, m+1, r);
    if(y <= m) return query(y, p<<1, l, m);
    pii z = query(y, p<<1|1, m+1, r);
    return pii(max(t[p<<1], ts[p<<1] + z.x), ts[p<<1] + z.y);
}

int getval(int x, int p = 1, int l = 0, int r = coor.size()-1) {
    push(p, l, r);
    if(l == r) return val[p];
    int m = (l + r) / 2;
    if(x <= m) return getval(x, p<<1, l, m);
    else return getval(x, p<<1|1, m+1, r);
}

int main() {
    fill_n(lz, N<<1, INF);
    scanf("%d", &n);
    coor.emplace_back(n);
    coor.emplace_back(n+1);
    while(true) {
        char t; scanf(" %c", &t); 
        int a, b, c;
        if(t == 'E') break;
        if(t == 'I') {
            scanf("%d %d %d", &a, &b, &c);
            vec.emplace_back(1, a, b, c);
            coor.emplace_back(a-1), coor.emplace_back(b);
        } else scanf("%d", &a), vec.emplace_back(0, a, 0, 0);
    }
    sort(all(coor));
    coor.resize(unique(all(coor)) - coor.begin());
    update(coor.size()-1, coor.size() - 1, 1000000001);
    // for(int i = 0; i < coor.size(); ++i) cerr << i << " => " << coor[i] << endl;
    for(auto &x : vec) {
        int z, l, r, v; tie(z, l, r, v) = x;
        if(z) {
            l = lower_bound(all(coor), l-1) - coor.begin() + 1;
            r = lower_bound(all(coor), r) - coor.begin();
            // cerr << "==> " << l << ' ' << r << endl;
            update(l, r, v);
        } else {
            // printf("{");
            // for(int i = 1; i < coor.size()-1; ++i) printf("%d, ", coor[i]);
            // printf("%d}\n", n+1);
            // for(int i = 1; i < coor.size(); ++i) cerr << coor[i] << ' ' << query(i).y << endl;
            int zz = l;
            int l = 0, r = coor.size()-1;
            while(l < r) {
                int m = (l + r + 1) / 2;
                if(query(m).x <= zz) l = m;
                else r = m-1;
            }
            int rr = l;
            // cerr << "-> " << l << endl;
            // cerr << query(2).x << ' ' << query(2).y << endl;
            // cerr << query(3).x << ' ' << query(3).y << endl;
            // cerr << zz << "-> " << l << endl;
            long v0 = query(l).y;
            // cerr << getval(l) <<  " -> " << getval(l+1) << endl;
            long v1 = getval(l+1);
            // cerr << v0 << " ====> " << v1 << endl ;
            l = 0, r = 1e9+1;
            while(l < r) {
                int m = (l + r + 1) / 2;
                if(v0 + v1 * m <= zz) l = m;
                else r = m-1;
            }
            printf("%d\n", coor[rr] + r);
        }
    }
}