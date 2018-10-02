#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1505;

int n, m, mx;
char buff[N];
bool is[N];
pii ret[2][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) ret[1][i] = pii(0, i);
    for(int i = 0; i < n; ++i) {
        scanf("%s", buff);
        int l = 0, r = m;
        for(int j = 0; j < m; ++j) is[j] = buff[j] == '1';
        for(int j = 0; j < m; ++j) {
            if(is[ret[~i&1][j].y]) ret[i&1][l] = ret[~i&1][j], ret[i&1][l].x++, mx = max(mx, ret[i&1][l].x * (l+1)), l++;
            else ret[i&1][--r] = ret[~i&1][j], ret[i&1][r].x = 0;
        } 
    }
    printf("%d\n", mx);
}
