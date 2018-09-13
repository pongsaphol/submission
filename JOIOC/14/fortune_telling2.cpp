#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define long long long
#define pii pair<int, int>
#define x first
#define y second

const int N = 2e5+5;

int n, k, t[N];
long ans;
vector<pii> que;
vector<int> coor, z[N];

int A[N], l[N], r[N];

void update(int x) {
    for(int i = x; i; i -= i & -i) t[i]++;
}

int query(int x) {
    int v = 0;
    for(int i = x; i <= coor.size() + 1; i += i & -i) v += t[i];
    return v;
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        que.emplace_back(a, b);
        r[i] = k;
    }
    coor.resize(1);
    for(int i = 1; i <= k; ++i) {
        scanf("%d", A+i);
        coor.emplace_back(A[i]);
    }
    sort(all(coor));
    coor.resize(unique(all(coor)) - coor.begin());
    for(int i = 0; i <= k; ++i) A[i] = upper_bound(all(coor), A[i]) - coor.begin();
    auto f = [&](int v) int { return query(lower_bound(all(coor), v) - coor.begin() + 1); };
    for(int it = 0; it < 18; ++it) {
        for(int i = 0; i < n; ++i) if(l[i] < r[i]) z[l[i] + r[i] + 1 >> 1].emplace_back(i);
        for(int i = k; ~i; --i) {
            update(A[i]);
            for(auto v : z[i]) {
                if(f(que[v].x) != f(que[v].y)) l[v] = i;
                else r[v] = i-1;
            }
            z[i].clear();
        }
        memset(t, 0, sizeof t);
    }
    for(int i = 0; i < n; ++i) z[l[i]].emplace_back(i);
    for(int i = k; ~i; --i) {
        update(A[i]);
        for(auto v : z[i]) {
            int a, b; tie(a, b) = que[v];
            if(i == 0) ans += f(a) & 1 ? b : a;
            else ans += f(max(a, b)) & 1 ? min(a, b) : max(a, b);
        }
    } 
    printf("%lld\n", ans);
}
