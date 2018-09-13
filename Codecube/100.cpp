#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 1e5+5;

int n, m;
int ent[128];
char str[] = "LOVE";
long pref[N][4][4];

int main() {
    for(int i = 0; i < 4; ++i) ent[str[i]] = i;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        char c; scanf(" %c", &c);
        int x = ent[c];
        for(int j = 0; j < 4; ++j) for(int k = 0; k < 4; ++k) pref[i][j][k] = pref[i-1][j][k];
        pref[i][x][x]++;
        for(int j = x-1; ~j; --j) pref[i][j][x] += pref[i-1][j][x-1];
    }
    
    int m; scanf("%d", &m);
    for(int i = 0, l, r; i < m; ++i) {
        scanf("%d %d", &l, &r);
        long ans = pref[r][0][3] - pref[l-1][0][3];
        long E = (pref[r][3][3] - pref[l-1][3][3]);
        ans -= pref[l-1][0][2] * E;
        long VE = (pref[r][2][3] - pref[l-1][2][3]) - (E * pref[l-1][2][2]);
        ans -= pref[l-1][0][1] * VE;
        long OVE = pref[r][1][3] - pref[l-1][1][3] - (E * pref[l-1][1][2]) - (VE * pref[l-1][1][1]);
        ans -= pref[l-1][0][0] * OVE;
        printf("%lld\n", ans);
    }
}
