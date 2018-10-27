#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int fast() {
    int x = 0;
    char c;
    while(c < '0' || c > '9') c = getchar();
    for(; c >= '0' and c <= '9'; c = getchar()) x = (x<<1) + (x<<3) + c - '0';
    return x;
}

int n, m;
int cost[N];
vector<int> g[N];
int d[N], step[N];
int dfs(int u, int s) {
    if(step[u] == s) return d[u];
    d[u] = 1, step[u] = s;
    for(int v : g[u]) d[u] = max(d[u], 1 + dfs(v, s));
    return d[u];
}

int main() {
    n = fast();
    m = fast();
    if(m == 0) {
        printf("%d\n", -1);
        return 0;
    }
    for(int i = 0; i < n; ++i) cost[i] = fast();
    int prev = 0;
    int l = 1, r = n-1;
    while(l < r) { 
        int mid = l + r >> 1;
        if(prev < mid) {
            for(int i = prev+1; i <= mid; ++i) {
                for(int j = 0; j < n; ++j) if(cost[j] < cost[(j+i) % n]) g[j].emplace_back((j+i)%n);
            }
        } else if(prev > mid) {
            for(int i = 0; i < n; ++i) {
                while(!g[i].empty() &&((g[i].back() - i + n) % n) > mid) g[i].pop_back();
            }
        }
        bool st = false;
        for(int j = 0; j < n; ++j) if(step[j] != mid) if(dfs(j, mid) > m) {
            st = true;
            break;
        }
        prev = mid;
        if(st) r = mid;
        else l = mid+1;
    }
    printf("%d\n", r);
}
