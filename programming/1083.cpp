#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, m, qs[N];

int main() {
    int x, y;
    scanf("%d %d", &n, &x);
    for(int i = 2; i <= n; ++i) {
        scanf("%d", &y);
        int d = y - x;
        qs[i] = qs[i-1] + max(0, d);
        x = y;
    }
    scanf("%d", &m);
    for(int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        printf("%d\n", qs[b] - qs[a]);
    }
}