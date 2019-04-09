#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1<<17;

int n, inp[N];
long ans;
vector<int> t[N<<1];

template<typename T>
void query(int l, int r, const T &f)  {
    for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if(l & 1) f(l++);
        if(r & 1) f(--r);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0, val; i < n; ++i) scanf("%d", inp+i), t[i+N].emplace_back(inp[i]);
    for(int i = N-1; i; --i)
        merge(t[i<<1].begin(), t[i<<1].end(), t[i<<1|1].begin(), t[i<<1|1].end(), back_inserter(t[i]));
    for(int i = 0, d; i < n; ++i) {
        scanf("%d", &d);
        query(max(0, i-d), i, [&](int p) {
            ans += t[p].size() - (upper_bound(t[p].begin(), t[p].end(), inp[i]) - t[p].begin());
        });
        query(i+1, min(n, i+d+1), [&](int p) {
            ans += lower_bound(t[p].begin(), t[p].end(), inp[i]) - t[p].begin();
        });
    }
    printf("%lld\n", ans);
}
/*
5
5 4 3 2 1
0 1 2 3 4
*/
