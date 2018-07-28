#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1e5+5;

int n, m, q;
int L[N], R[N], X[N], Y[N], P[N];
vector<int> ls[N];

int find(int x) { return P[x] = P[x] == x ? x : find(P[x]); }

int main() {    
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < q; ++i) scanf("%d %d", X+i, Y+i), L[i] = 1, R[i] = m;
    for(int it = 0; it < 18; ++it) {
        iota(P, P + N, 0);
        for(int i = 0; i < q; ++i) if(L[i] < R[i]) ls[L[i]+R[i] >> 1].emplace_back(i);
        for(int i = 1; i <= m; ++i) {
            int z = m - i + 1;
            for(int i = z + z; i <= n; i += z) {
                int u = find(z), v = find(i);
                if(u != v) P[u] = v;
            }
            for(auto now : ls[i]) {
                if(find(X[now]) == find(Y[now])) R[now] = i;
                else L[now] = i+1; 
            }
            ls[i].clear();
        }
    }
    for_each(R, R + q, [](int x) { printf("%d\n", x); });
}