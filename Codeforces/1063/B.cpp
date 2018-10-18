#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 2e3+5;
const pii inf = pii(1e9, 1e9);

int n, m, r, c;
int lm, rm;
pii d[N][N];
char A[N][N];

struct data {
    int x, y, mn;
    data(int x, int y, int mn) : x(x), y(y), mn(mn) {}
    friend inline bool operator<(const data &a, const data &b) {
        return a.mn > b.mn;
    }
};

bool check(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m) return false;
    if(A[x][y] == '*') return false;
    if(d[x][y] == inf) return true;
    return false;
}

int main() {
    fill_n(d[0], N*N, inf);
    scanf("%d %d %d %d", &n, &m, &r, &c);
    scanf("%d %d", &lm, &rm);
    for(int i = 1; i <= n; ++i) scanf("%s", A[i]+1);
    d[r][c] = pii(0, 0);
    priority_queue<data> Q;
    Q.emplace(r, c, 0);
    while(!Q.empty()) {
        auto now = Q.top(); Q.pop();
        int x = now.x, y = now.y;
        if(check(x+1, y)) d[x+1][y] = d[x][y], Q.emplace(x+1, y, max(d[x+1][y].x, d[x+1][y].y));
        if(check(x-1, y)) d[x-1][y] = d[x][y], Q.emplace(x-1, y, max(d[x-1][y].x, d[x-1][y].y));
        if(check(x, y+1) and d[x][y].y < rm) d[x][y+1] = d[x][y], d[x][y+1].y++, Q.emplace(x, y+1, max(d[x][y+1].x, d[x][y+1].y));
        if(check(x, y-1) and d[x][y].x < lm) d[x][y-1] = d[x][y], d[x][y-1].x++, Q.emplace(x, y-1, max(d[x][y-1].x, d[x][y-1].y));
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) if(d[i][j] != inf) cnt++;
    printf("%d\n", cnt);
}
