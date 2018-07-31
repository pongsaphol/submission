#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pii pair<int, int>
#define x first
#define y second

int n;
vector<pii> V, A;

int main() {
    scanf("%d", &n); 
    V.reserve(n+1), A.reserve(n+1);
    for(int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        V.emplace_back(a, b);
    }
    sort(V.begin(), V.end(), [&](const pii &a, const pii &b) {
        if(a.x == b.x) return a.y < b.y;
        return a.x > b.x;
    });
    A.emplace_back(V[0]);
    for(int i = 1; i < n; ++i) {
        if(V[i].y > A.back().y) A.emplace_back(V[i]);
    }
    int pv = 0;
    long sum = 0;
    for(auto x : A) {
        sum += 1ll * x.x * (x.y - pv);
        pv = x.y;
    }
    printf("%lld\n", sum);
}
