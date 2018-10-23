#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m, k;
int P[N];

int find(int u) { return P[u] = P[u] == u ? u : find(P[u]); }

int main() {
    scanf("%d %d %d", &n, &m, &k);
    iota(P, P+N, 0);
    for(int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        a = find(a), b = find(b);
        P[a] = b;
    }
    for(int i = 0, a, b; i < k; ++i) {
        scanf("%d %d", &a, &b);
        puts(find(a) == find(b) ? "yes" : "no");
    }
}
