#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define iiii tuple<int, int, int, int>
#define x first
#define y second

int n;
int A[15][15];
int dp[15][15][105][3];
pii pos[105];

int x[] = {2, 2, -2, -2, -1, -1, 1, 1};
int y[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
    scanf("%d", &n);
    fill_n(dp[0][0][0], 15*15*105*3, 1000000000);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        scanf("%d", &A[i][j]);
        pos[A[i][j]] = pii(i, j);
    }
    queue<iiii> Q;
    dp[pos[1].x][pos[1].y][1][0] = 0;
    dp[pos[1].x][pos[1].y][1][1] = 0;
    dp[pos[1].x][pos[1].y][1][2] = 0;
    Q.emplace(pos[1].x, pos[1].y, 1, 0);
    Q.emplace(pos[1].x, pos[1].y, 1, 1);
    Q.emplace(pos[1].x, pos[1].y, 1, 2);
    while(!Q.empty()) {
        auto now = Q.front(); Q.pop();
        int x, y, last, mask; tie(x, y, last, mask) = now;
        if(mask == 0) {
            for(int i = 0; i < 8; ++i) {
                int a = x + ::x[i], b = y + ::y[i];
                if(a < 0 || a > n || b < 0 || b > n) continue;
                int z = last;
                if(A[a][b] = z+1) z++;
                if(dp[a][b][z][mask] > dp[x][y][last][mask] + 1) dp[a][b][z][mask] = dp[x][y][last][mask] + 1, Q.emplace(a, b, z, mask);
            } 
        } 
        if(mask == 1) {
            int z1[] = {1, 1, -1, -1};
            int z2[] = {-1, 1, -1, 1};
            for(int i = 0; i < 4; ++i) {
                for(int j = 1; j <= 10; ++j) {
                    int a = x + z1[i] * j, b = y + z2[i] * j;
                    if(a < 0 || a > n || b < 0 || b > n) continue;
                    int z = last;
                    if(A[a][b] = z+1) z++;
                    if(dp[a][b][z][mask] > dp[x][y][last][mask] + 1) dp[a][b][z][mask] = dp[x][y][last][mask] + 1, Q.emplace(a, b, z, mask);
                }
            }
        } 
        if(mask == 2) {
            int z1[] = {1, -1, 0, 0};
            int z2[] = {0, 0, -1, 1};
            for(int i = 0; i < 4; ++i) {
                for(int j = 1; j <= 10; ++j) {
                    int a = x + z1[i] * j, b = y + z2[i] * j;
                    if(a < 0 || a > n || b < 0 || b > n) continue;
                    int z = last;
                    if(A[a][b] = z+1) z++;
                    if(dp[a][b][z][mask] > dp[x][y][last][mask] + 1) dp[a][b][z][mask] = dp[x][y][last][mask] + 1, Q.emplace(a, b, z, mask);
                }
            }
        }
        for(int i = 0; i < 3; ++i) if(i != mask) {
            if(dp[x][y][last][i] > dp[x][y][last][mask] + 1) dp[x][y][last][i] = dp[x][y][last][mask] + 1, Q.emplace(x, y, last, i);
        }
    }
    printf("%d\n", dp[3][1][4][2]);
    int z = n * n;
    printf("%d\n", min({dp[pos[z].x][pos[z].y][z][0], dp[pos[z].x][pos[z].y][z][2], dp[pos[z].x][pos[z].y][z][1]}));
}
