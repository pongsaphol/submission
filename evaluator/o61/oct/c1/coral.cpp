#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1<<20;

int n, k, m;

int t[N<<1];

void fastscan(int &x) {
    x = 0;
    int c = 0;
    while(c < '0' || c > '9') c = getchar();
    for(; c >= '0' && c <= '9'; c = getchar()) x = (x<<1) + (x<<3) + c - '0';
}

bool have[N<<1];

bool f(int m) {
    bool ans = true;
    for(int i = 0; i < n; ++i) have[i+n] = t[i+n] > 0 && t[i+n] <= m;
    for(int p = n-1; p; --p) {
        if(have[p<<1] && have[p<<1|1]) have[p] = true;
        else if(!have[p<<1] && !have[p<<1|1]) ans = false;
        else have[p] = t[p] > 0 && t[p] <= m;
    }
    return ans && have[1];
}

int main() {
    fastscan(k), fastscan(m);
    n = 1 << k;
    for(int i = 0, a, b; i < m; ++i) {
        fastscan(a), fastscan(b);
        int l = b, r = b + (1<<a);
        for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) {
                t[l] = i+1;
                break;
            }
            if(r & 1) {
                t[--r] = i+1;
                break;
            }
        }
    }
    int l = 1, r = m;
    while(l < r) {
        int m = l + r >> 1;
        if(f(m)) r = m;
        else l = m+1;
    }
    printf("%d\n", r);
}
