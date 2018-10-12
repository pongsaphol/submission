#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 2e5+5;

int n, k;

long pref[N];
int dp[N];
int t[N<<1];

void update(int x, int v) {
    for(t[x+=N] = v; x != 1; x >>= 1) t[x>>1] = min(t[x], t[x^1]);
}

int query(int l, int r) {
    int mn = 1e9;
    for(l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
        if(l & 1) mn = min(mn, t[l++]);
        if(r & 1) mn = min(mn, t[--r]);
    }
    return mn;
}

int main() {
    scanf("%d %d", &n, &k);
    int z = 2e5;
    for(int i = 0; i < n; ++i) {
        int h; scanf("%d", &h);
        pref[z-h+1]++;
    }
    for(int i = 1; i <= z; ++i) pref[i] += pref[i-1];
    for(int i = 1; i <= z; ++i) pref[i] += pref[i-1];
    pref[z+1] = n;
    deque<int> Q;
    Q.push_back(1);
    int ptr = 0;
    for(int i = 2; i <= z+1; ++i) {
        while(pref[i-1] - pref[ptr] > k) ptr++;
        update(i, dp[i] = 1 + query(ptr+1, i-1));
        if(pref[i] - pref[i-1] == n) return !printf("%d\n", dp[i]);
    }
}

