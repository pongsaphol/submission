#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int k, n, m, o;

int main() {
    scanf("%d %d %d %d", &k, &n, &m, &o);
    int h = n/k+1;
    vector<vector<vector<vector<int>>>> d(h, vector<vector<vector<int>>>(k, vector<vector<int>>(16, vector<int>(k, INF))));
    for(int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        d[a/k][a%k][0][b%k] = c; 
    }
    for(int z = 1; z < 16; ++z) for(int i = 0; i < h; ++i) for(int j = 0; j < k; ++j) for(int x = 0; x < k; ++x) for(int y = 0; y < k; ++y) 
       if(i + (1<<(z-1)) < h) d[i][j][z][x] = min(d[i][j][z][x], d[i][j][z-1][y] + d[i+(1<<(z-1))][y][z-1][x]);
    for(int i = 0, a, b; i < o; ++i) {
        scanf("%d %d", &a, &b);
        if(a/k >= b/k) {
            puts("-1");
            continue;
        }
        vector<int> ret = d[a/k][a%k][0];
        int p = b % k; 
        a = (a / k) + 1, b = b / k;
        for(int j = 15; ~j; --j) if(a + (1 << j) <= b) {
            vector<int> nret(k, INF);
            for(int x = 0; x < k; ++x) for(int y = 0; y < k; ++y) 
                nret[y] = min(nret[y], ret[x] + d[a][x][j][y]);
            a += (1 << j);
            ret = nret;
        }
        printf("%d\n", ret[p] == INF ? -1 : ret[p]);
    } 
}
