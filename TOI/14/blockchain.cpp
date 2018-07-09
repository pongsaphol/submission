#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, m;
map<vector<pii>, int> M;

vector<pii> readTree() {
    int z; scanf("%d", &z);
    vector<pii> V;
    for(int i = 1, u, v; i < z; ++i) {
        scanf("%d %d", &u, &v);
        if(u > v) swap(u, v);
        V.emplace_back(u, v);
    }
    sort(V.begin(), V.end());
    return V;
}

int main() {
    scanf("%d %d", &n, &m);
    while(n--) M[readTree()]++;
    while(m--) printf("%d\n", M[readTree()]);
}