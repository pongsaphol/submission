#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    int n, t; scanf("%d %d", &n, &t);
    int mn = inf;
    for(int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        if(b <= t) mn = min(mn, a);
    }
    if(mn == inf) puts("TLE");
    else printf("%d\n", mn);
}
