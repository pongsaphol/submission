#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<int> V;
    V.emplace_back(m);
    for(int i = 0, ret; i < n; ++i) {
        scanf("%d", &ret);
        V.emplace_back(ret);
    }
    sort(V.begin(), V.end());
    int gcd = V[1] - V[0];
    for(int i = 2; i <= n; ++i) gcd = __gcd(gcd, V[i] - V[i-1]);
    printf("%d\n", gcd);
}
