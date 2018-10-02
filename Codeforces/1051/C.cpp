#include <bits/stdc++.h>
using namespace std;

const int N = 105;

vector<int> pos[N];
vector<int> sz[N];
char ans[N];

int main() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int ret; scanf("%d", &ret);
        pos[ret].emplace_back(i);
    }
    for(int i = 1; i <= 100; ++i) sz[pos[i]].emplace_back(i);
    for(int i = 0; i < sz[1].size(); ++i) ans[pos[sz[1][i]][0]] = (i % 2 ? 'A' : 'B');
    for(int i = 0; i < sz[2].size(); ++i) ans[pos[sz[2][i]][0]] = ans[pos[sz[2][i]][1]]= (i % 2 ? 'A' : 'B');
    if(sz[1] % 2) {}
}
