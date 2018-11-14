#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5;

int n, t[N];
vector<pii> V;

int num[N];

void update(int x, int v) {
    for(int i = x; i > 0; i -= i & -i) t[i-1] += v;
}

int query(int x, int v = 0) {
    for(int i = x; i <= N; i += i & -i) v += t[i-1];
    return v;
}

int getft(int x) {
    int l = 0, r = N;
    while(l < r) {
        int m = (l + r + 1) >> 1;
        if(query(m) >= x) l = m;
        else r = m-1;
    }
    return l;
}

int main() {
    scanf("%d", &n);
    for(int i = 0, a, b; i < n; ++i) scanf("%d %d", &a, &b), V.emplace_back(a, b);
    sort(V.begin(), V.end());
    for(auto x : V) {
        int h, k; tie(h, k) = x;
        int p = h - k;
        update(h, 1);
        if(!p) continue;
        int lb = min(getft(query(p)), h), rb = getft(query(p) + 1); 
        update(lb, -1), update(rb, -1);
        update(rb+k-(h-lb), 1);
    }   
    long ans = 0;
    for(int i = 1; i <= N; ++i) ans += 1ll * query(i) * (query(i)-1) / 2;
    printf("%lld\n", ans);
}
