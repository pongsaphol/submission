#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second
#define long long long

int n;
long ans;

int main() {
    stack<pii> S;
    scanf("%d", &n);
    for(int i = 1, val; i <= n; ++i) {
        scanf("%d", &val);
        while(!S.empty() && S.top().x < val) ans += S.top().y, S.pop();
        int sz = 1;
        if(!S.empty() && S.top().x == val) sz += S.top().y, ans += S.top().y, S.pop();
        if(!S.empty() and S.top().x > val) ans++;
        S.emplace(val, sz);
    }
    printf("%lld\n", ans);
}
