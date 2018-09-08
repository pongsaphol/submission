#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1<<17;

int n, m;
int A[N], pref[N], ans[N];

int t[N<<1], lz[N<<1];

#define all int p = 1, int l = 0, int r = m-1
#define mid (l + r >> 1)
#define lb p<<1, l, mid
#define rb p<<1|1, mid+1, r

void push(all) {
    if(!lz[p]) return;
    if(l != r) lz[p<<1] = lz[p<<1|1] = lz[p];
    else t[p] = lz[p];
    lz[p] = 0;
}

void update(int x, int y, int v, all) {
    if(lz[p]) push(p, l, r);
    if(x <= l && r <= y) { lz[p] = v, push(p, l, r); return; }
    if(x > r || l > y) return;
    update(x, y, v, lb), update(x, y, v, rb);
}

int query(int x, all) {
    push(p, l, r);
    if(l == r) return t[p];
    if(x <= mid) return query(x, lb);
    return query(x, rb);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    vector<pii> que; 
    for(int i = 0, x; i < m; ++i) {
        scanf("%d", &x);
        que.emplace_back(x, i);
    }
    sort(que.begin(), que.end());
    update(0, m-1, A[1]);
    for(int i = 2; i <= n; ++i) {
        int l = 0, r = m;
        while(l < r) {
            int m = l + r >> 1;
            if(query(m) + que[m].x >= A[i]) r = m;
            else l = m+1;
        }
        pref[0]++, pref[r]--;
        update(r, m-1, A[i]);
    }
    for(int i = 1; i < m; ++i) pref[i] += pref[i-1];
    for(int i = 0; i < m; ++i) ans[que[i].y] = pref[i]; 
    for(int i = 0; i < m; ++i) printf("%d\n", ans[i]);
}
