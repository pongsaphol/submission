#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 2e6+5, M = 1e9+7;

long F[N];
vector<vector<int> > prime(N);
bool is[N];

long powz(long a, long b) {
    long ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return ret;
}

int main() {
    F[0] = 1;
    for(int i = 1; i < N; ++i) F[i] = F[i-1] * i % M;
    for(int i = 2; i < N; i += 2) prime[i].emplace_back(2), is[i] = true;
    for(int i = 3; i < N; i += 2) if(!is[i])
        for(int j = i; j < N; j += i) prime[j].emplace_back(i), is[j] = true;
    int m; scanf("%d", &m);
    while(m--) {
        int x, y; scanf("%d %d", &x, &y);
        long ans = powz(2, y-1);
        for(auto i : prime[x]) {
            int cnt = 0;
            while(x % i == 0) x /= i, cnt++;
            ans = (ans * (F[cnt + y - 1] * (powz(F[cnt] * F[y-1] % M, M-2)) % M)) % M;
        }
        if(--x) ans = ans * y % M;
        printf("%lld\n", ans);
    }
}
