#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pll pair<long, long>
#define x first
#define y second

int n;
long pref, ans, lhs = -1e18;

int main() {
    scanf("%d", &n);
    vector<pll> V; V.reserve(n+1);
    for(int i = 0; i < n; ++i) {
        long a, b; scanf("%lld %lld", &a, &b);
        V.emplace_back(a, b);
    }
    sort(V.begin(), V.end());
    for(int i = 0; i < n; ++i) {
        long a, b; tie(a, b) = V[i];
        lhs = max(lhs, a - pref);
        pref += b;
        ans = max(ans, pref - a + lhs);
    }
    printf("%lld\n", ans);
}