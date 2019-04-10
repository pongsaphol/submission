/*
 let fix row1, col1
 a[i][j] = a[1][1] ^ a[1][j] ^ a[i][1] ^ ((i % 2 == 0) && (j % 2 == 0))
 a[1][j] ^ a[i][1] = a[i][j] ^ a[1][1] ^ ((i % 2 == 0) && (j % 2 == 0))
 solve with fix a[1][1] to true and false
 I will solve with count component of bipartite graph
 if a[1][j] ^ a[i][1] = 0 -> a[1][j] == a[i][1] -> addEdge(a[1][j], z), addEdge(z, a[i][1])
 if(a[1][j] ^ a[i][1] = 1 -> a[1][j] != a[i][1] -> addEdge(a[1][j], a[i][1])
 answer = 2^(component)
*/
#include <bits/stdc++.h>
#define iii tuple<int, int, int>

using namespace std;

const int N = 3e5+5;
const int M = 1e9;

int n, m, t;
int ans, col[N];
bool visit[N];
vector<iii> vec;
vector<vector<int>> g;
int getpos(int x, int y) {
    if(x == 1) return y-2;
    else return x+m-3;
}

void addEdge(int u, int v) {
    g[u].emplace_back(v), g[v].emplace_back(u);
}

void dfs(int u) {
    visit[u] = true;
    for(int v : g[u]) {
        if(col[v] && col[v] != (col[u] ^ 3)) ans = 0; 
        else col[v] = col[u] ^ 3;
        if(!visit[v]) dfs(v);
    }
}

int solve(int status) {
    g = vector<vector<int>>(N);
    memset(col, 0, sizeof col), memset(visit, 0, sizeof visit);
    int p = n+m-2;
    for(auto z : vec) {
        int x, y, c; tie(x, y, c) = z;
        if(x == 1 || y == 1) {
            if(x == 1 && y == 1) {
                if(status != c) return 0;
            } else col[getpos(x, y)] = c+1;
            continue;
        }
        bool now = c ^ status ^ ((~x&1) && (~y&1));
        int u = getpos(1, y), v = getpos(x, 1);
        if(now) addEdge(u, v);
        else addEdge(u, p), addEdge(p, v), ++p;
    }
    ans = 1;
    for(int i = 0; i < n+m-2; ++i) if(!visit[i] && col[i]) 
        dfs(i);
    for(int i = 0; i < n+m-2; ++i) if(!visit[i]) 
        col[i] = 1, dfs(i), ans = (ans * 2) % M;
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 0, x, y, c; i < t; ++i) {
        scanf("%d %d %d", &x, &y, &c);
        vec.emplace_back(x, y, c); 
    }
    printf("%d\n", (solve(0) + solve(1)) % M);
}
