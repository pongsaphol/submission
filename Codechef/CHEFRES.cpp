#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

void solve() {
    int n, m;
    vector<pii> V;
    vector<int> V2;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        V2.emplace_back(a);
        V.emplace_back(a, b);
    }
    sort(V.begin(), V.end());
    sort(V2.begin(), V2.end());
    while(m--) {
        int x; scanf("%d", &x);
        int pos = upper_bound(V2.begin(), V2.end(), x) - V2.begin() - 1;
        if(pos == -1) printf("%d\n", V2[0] - x);
        else if(V[pos].y <= x) {
            pos++;
            if(pos == n) puts("-1");
            else printf("%d\n", V2[pos] - x);
        }  else puts("0");
    }

}

int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
}
