#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 3e2+5;

int n, m;
long dpl[N][N][2], dpr[N][N][2];
int x[N], pos0 = 1;

int main() {
    scanf("%d %d", &n, &m);
    n++;
    for(int i = 1; i < n; ++i) scanf("%d", x+i), pos0 += x[i] < 0;
    sort(x+1, x+n+1);
    x[0] = -1000001, x[n+1] = 1000001;
    long ans = 0;
    for(int k = 1; k < n; ++k) {
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
            dpl[i][j][k&1] = min(dpl[i-1][j][~k&1] + k*(x[i] - x[i-1]), dpr[i][j+1][~k&1] + k*(x[j+1] - x[i]));
            dpr[i][j][k&1] = min(dpl[i-1][j][~k&1] + k*(x[j] - x[i-1]), dpr[i][j+1][~k&1] + k*(x[j+1] - x[j]));
        }
        ans = max(ans, k*m - dpl[pos0][pos0][k&1]);
    }
    printf("%lld\n", ans);
}
