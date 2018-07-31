#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+5;

int n, m, q, p[N];

int find(int x) { return p[x] = x == p[x] ? x : find(p[x]); }

int main() {
    scanf("%d %d %d", &n, &m, &q);
    iota(p, p+N, 0);
    int cnt = n+m-1;
    for(int i = 0, a, b; i < q; ++i) {
        scanf("%d %d", &a, &b);
        a = find(a-1), b = find(b+n-1);
        if(a != b) {
            p[a] = b;
            cnt--;
        }
    }
    printf("%d\n", cnt);
}