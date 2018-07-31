#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> V;
    for(int i = 1, ret; i <= 2*n; ++i) scanf("%d", &ret), V.emplace_back(ret);
    sort(V.begin(), V.end());
    long long ans = 1ll * (V[n-1] - V[0]) * (V[2*n-1] - V[n]);
    for(int i = n+1; i <= 2*n-1; ++i) {
        ans = min(ans, 1ll * (V[i-1] - V[i-n]) * (V[2*n-1] - V[0]));
    }
    printf("%lld\n", ans);
}