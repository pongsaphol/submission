#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int n, m, q, pf[N], ps[N];
char A[N], B[N];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    scanf("%s %s", A + 1, B + 1);
    for(int i = 1; i <= n - m + 1; ++i) {
        bool st = true;
        for(int j = 1; j <= m; ++j) {
            if(A[i+j-1] != B[j]) st = false;
        }
        if(st) pf[i]++;
    }
    for(int i = 1; i <= n; ++i) pf[i] += pf[i-1], ps[i] += ps[i-1];
    while(q--) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", max(0, pf[b-m+1] - pf[a-1]));
    }
}