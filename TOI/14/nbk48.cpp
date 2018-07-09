#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    vector<pii> V;
    int sum = 0;
    V.emplace_back((int)-1e9-1, 0);
    for(int i = 1, ret; i <= n; ++i) scanf("%d", &ret), sum += ret, V.emplace_back(sum, i); 
    sort(V.begin(), V.end());
    for(int i = 1; i <= n; ++i) V[i].y = max(V[i].y, V[i-1].y);
    for(int i = 0, a; i < m; ++i) {
        scanf("%d", &a);
        int id = upper_bound(V.begin(), V.end(), pii(a, (int)1e9)) - V.begin() - 1;
        printf("%d\n", V[id].y);
    }
}