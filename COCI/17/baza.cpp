#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int n, m, q, ret[N], A[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) scanf("%d", A[i]+j);
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        for(int j = 1; j <= m; ++j) scanf("%d", ret+j);
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            bool st = true;
            for(int j = 1; j <= m; ++j) {
                if(ret[j] == -1) continue;
                if(A[i][j] != ret[j]) st = false;
            }
            sum += st;
        }
        printf("%d\n", sum);
    } 
}