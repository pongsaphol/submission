#include <bits/stdc++.h>
using namespace std;

#define long long long
#define all(x) x.begin(), x.end()
#define pii pair<long, long>
#define x first
#define y second

const int N = 1e5+5;

int n;
long v;
vector<pii> A, ret;

int main() {
    scanf("%d", &n);
    for(int i = 0, a, b; i < n; ++i) 
        scanf("%d %d", &a, &b), ret.emplace_back(a, b);
    scanf("%lld", &v);
    for(auto &x : ret) 
        A.emplace_back(x.y * v + x.x, x.y * v - x.x);
    sort(all(A));
    vector<long> V;
    for(auto &x : A) {
        auto it = upper_bound(all(V), x.y);
        if(it == V.end()) V.emplace_back(x.y);
        else *it = x.y;
    }
    int ans = V.size(); V.clear();
    for(auto &x : A) if(x.x >= 0 and x.y >= 0) {
        auto it = upper_bound(all(V), x.y);
        if(it == V.end()) V.emplace_back(x.y);
        else *it = x.y;
    }
    printf("%d %d\n", (int)V.size(), ans);
}