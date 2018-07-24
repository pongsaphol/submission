#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, m;
vector<pii> V;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        V.emplace_back(a, b);
    }
    sort(V.begin(), V.end(), [&](const pii &a, const pii &b) { return a.y < b.y; });
    int ret = 0, cnt = 0;
    for(pii w : V) if(ret <= w.x) ret = w.y, cnt++;
    printf("%d\n", cnt);
}