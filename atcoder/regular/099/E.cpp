#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 705;

int n, m;
bool g[N][N];

int c2(int x) { return x * (x - 1) / 2; }

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) g[i][i] = true;
    for(int i = 0, u, v; i < m; ++i) {
        scanf("%d %d", &u, &v); 
        g[u][v] = g[v][u] = true;
    }
    vector<int> col(N);
    bitset<N> chk[2]; chk[0][0] = true;
    bool st = false;
    auto f = [&](int v) {
        for(int i = n - v; ~i; --i) if(chk[st^1][i]) chk[st][i+v] = true;
    };
    for(int i = 1; i <= n; ++i) if(!col[i]) {
        st ^= 1;
        chk[st] = bitset<N>();
        queue<int> Q; Q.emplace(i); col[i] = 1;
        int cnt1 = 0, cnt2 = 0;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            if(col[u] == 1) cnt1++;
            if(col[u] == 2) cnt2++;
            for(int v = 1; v <= n; ++v) if(!g[u][v]) {
                if(!col[v]) col[v] = col[u] ^ 3, Q.emplace(v);
                if(col[v] == col[u]) return !printf("-1\n");
            }
        }
        f(cnt1), f(cnt2);
    }
    int mn = 1e9;
    for(int i = 0; i <= n; ++i) if(chk[st][i]) mn = min(mn, c2(i) + c2(n-i));
    printf("%d\n", mn);
}
