#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

int x[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int y[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int n;
int xz, yz, x2, y2, x3, y3;
int val[1005][1005];


int main() {
    scanf("%d %d %d %d %d %d %d", &n, &xz, &yz, &x2, &y2, &x3, &y3);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        if(abs(xz - i) == abs(yz - j)) val[i][j] = -1;
        else if(xz == i || yz == j) val[i][j] = -1;
    }
    queue<pii> Q;
    Q.emplace(x2, y2);
    while(!Q.empty()) {
        auto now = Q.front(); Q.pop();
        for(int i = 0; i < 8; ++i) {
            int x = now.x + ::x[i], y = now.y + ::y[i];
            if(x < 1 || x > n || y < 1 || y > n) continue;
            if(val[x][y] == 0) val[x][y] = 1, Q.emplace(x, y); 
        }
    }
    puts((val[x3][y3] == 1) ? "YES" : "NO"); 
}
