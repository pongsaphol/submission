#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, A[N], pos[N], cnt[N];
vector<int> g[N];
char ans[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i), pos[A[i]] = i;
    for(int i = 1; i <= n; ++i) {
        for(int j = pos[i]; j > 0; j -= i) if(A[j] > i) g[A[j]].emplace_back(i), cnt[i]++;
        for(int j = pos[i]; j <= n; j += i) if(A[j] > i) g[A[j]].emplace_back(i), cnt[i]++;
    }
    queue<int> Q;
    for(int i = 1; i <= n; ++i) if(!cnt[i]) Q.emplace(i);
    while(!Q.empty()) {
        auto now = Q.front(); Q.pop();
        if(!ans[now]) ans[now] = 'B';
        for(int v : g[now]) {
            if(ans[now] == 'B') ans[v] = 'A';
            if(!--cnt[v]) Q.emplace(v);
        }
    }
    for(int i = 1; i <= n; ++i) printf("%c", ans[A[i]]);
}
