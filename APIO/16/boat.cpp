#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
 
const int N = 1e3+5;
const int M = 1e9+7;
 
int n;
int dp[N], pf[N][N];
vector<int> coor, vec[N];
vector<pii> que;
 
int powMod(int a, int b) {
    int val = 1;
    for(; b; b >>= 1) {
        if(b & 1) val = (1ll * val * a) % M;
        a = (1ll * a * a) % M;
    } 
    return val;
}
 
int f(int i, int x) {
    int up = 1, down = 1;
    for(int j = x; j < i+x; ++j) up = (1ll * up * j) % M;
    for(int j = 1; j <= i; ++j) down = (1ll * down * j) % M;
    return (1ll * up * powMod(down, M-2)) % M;
}

int pref[N];
 
int main() {
    scanf("%d", &n);
    dp[0] = 1, coor.emplace_back(0);
    for(int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b), b++;
        coor.emplace_back(a), coor.emplace_back(b);
        que.emplace_back(a, b);
    }
    sort(all(coor));
    for(int i = 0, l, r; i < n; ++i) {
        tie(l, r) = que[i];
        l = lower_bound(all(coor), l) - coor.begin(), r = lower_bound(all(coor), r) - coor.begin();
        pref[l]++, pref[r]--;
    }
    for(int i = 1; i < coor.size()-1; ++i) {
        pref[i] += pref[i-1];
        for(int j = 1; j <= pref[i]; ++j) pf[i][j] = f(j, coor[i+1] - coor[i]);
    }
    for(int i = 0, l, r; i < n; ++i) {
        tie(l, r) = que[i];
        l = lower_bound(all(coor), l) - coor.begin(), r = lower_bound(all(coor), r) - coor.begin();
        for(int z = r-1, sum = 0; z >= l; --z, sum = 0) {
            for(int k = z-1; ~k; --k) sum = (sum + dp[k]) % M;
            vec[z].emplace_back(sum), dp[z] = 0;
            int sz = vec[z].size();
            for(int j = 0; j < sz; ++j) dp[z] = (dp[z] + 1ll * vec[z][j] * pf[z][sz-j]) % M;
        }
    } 
    int ans = 0;
    for(int i = 1; i < coor.size()-1; ++i) ans = (ans + dp[i]) % M;
    printf("%d\n", ans);
}