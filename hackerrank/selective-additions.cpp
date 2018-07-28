#include <bits/stdc++.h>
using namespace std;

#define iii tuple<int, int, int>
#define long long long                                          

const int N = 1<<17;

int n, m, k, A[N], pos[N];
int t[N];
int L[N], R[N];
vector<int> ls[N];

int query(int x) {
    int sum = 0;
    for(; x; x -= x & -x) sum += t[x];
    return sum;
}

void upd(int x, int v) {
    for(; x < N; x += x & -x) t[x] += v;
}

void update(int l, int r, int x) {
    upd(l, x), upd(r+1, -x);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    fill_n(pos, N, N);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    vector<int> DF;
    for(int i = 0, ret; i < k; ++i) scanf("%d", &ret), DF.emplace_back(ret);
    sort(DF.begin(), DF.end());
    vector<iii> Q;
    Q.reserve(m+5);
    Q.emplace_back(1, n, 0);
    for(int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        Q.emplace_back(a, b, c);
    }
    for(int z : DF) {
        fill_n(L, N, 0);
        fill_n(R, N, m);
        for(int iter = 0; iter < 17; ++iter) {
            for(int i = 1; i <= n; ++i) if(pos[i] == N && L[i] < R[i]) ls[L[i]+R[i]>>1].emplace_back(i);
            for(int i = 0; i <= m; ++i) {
                int l, r, v; tie(l, r, v) = Q[i];
                update(l, r, v);
                for(int x : ls[i]) {
                    if(query(x) + A[x] >= z) R[x] = i;
                    else L[x] = i+1;
                }
                ls[i].clear();
            }
            memset(t, 0, sizeof t);
        }
        for(int i = 1; i <= n; ++i) if(pos[i] == N) ls[R[i]].emplace_back(i);
        for(int i = 0; i <= m; ++i) {
            int l, r, v; tie(l, r, v) = Q[i];
            update(l, r, v);
            for(int x : ls[i]) if(query(x) + A[x] == z) pos[x] = i;
            ls[i].clear();
        }
        memset(t, 0, sizeof t);
    }
    auto get = [&](int l, int r) { return query(r) - query(l-1); };
    for(int i = 1; i <= n; ++i) if(pos[i] != N) ls[pos[i]].emplace_back(i);
    long sum = 0; for_each(A, A+N, [&](int x) { sum += x; });
    for(int i = 1; i <= m; ++i) {
        for(auto x : ls[i-1]) update(x, N, 1); 
        int l, r, x; tie(l, r, x) = Q[i];
        printf("%lld\n", sum += 1ll * (r - l + 1 - get(l, r)) * x);
    }
}