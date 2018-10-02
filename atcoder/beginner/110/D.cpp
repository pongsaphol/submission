#include <bits/stdc++.h>
using namespace std;

#define long long long 

const long M = 1e9+7;
const int N = 2e5+5;

int n, m;

long frac[N];

long powmod(long a, long b) {
    long ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ret;
}

long c(int n, int r) {
    long ret = (frac[n] * powmod(frac[n-r], M-2)) % M; 
    return (ret * powmod(frac[r], M-2)) % M;
}

int main() {
    scanf("%d %d", &n, &m);
    frac[0] = 1;
    for(int i = 1; i < N; ++i) frac[i] = (frac[i-1] * i) % M;
    long ans = 1;
    for(int i = 2; i * i <= m; ++i) {
        int cnt = 0;
        while(m % i == 0) m /= i, cnt++;
        ans = (ans * c(cnt + n - 1, n - 1))% M;
    }
    if(m != 1) ans = (ans * n) % M;
    printf("%lld\n", ans);
}
