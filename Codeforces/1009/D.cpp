#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, m;

int gcd(int a, int b) {
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    scanf("%d %d", &n, &m);
    if(m >= n-1) {
    vector<pii> V;
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            if(gcd(i, j) == 1) V.emplace_back(i, j);
            if(V.size() == m) {
                puts("Possible");
                for(auto x : V) printf("%d %d\n", x.x, x.y);
                return 0;
            }
        }
    }}
    printf("Impossible\n");
}
