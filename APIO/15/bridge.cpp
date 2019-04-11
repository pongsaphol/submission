#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define x first
#define y second
#define long long long
using namespace std;

const int N = 1e5+5;

int k, n, sz;
vector<pii> vec;
long ans;
long dp[2][N];

void solve_median(int z) {
    priority_queue<int> Q1;
    priority_queue<int, vector<int>, greater<int> > Q2;
    long sum1 = 0, sum2 = 0;
    for(int i = 0; i < sz; ++i) {
        Q1.emplace(vec[i].x), sum1 += vec[i].x;
        Q2.emplace(vec[i].y), sum2 += vec[i].y;
        if(Q1.top() > Q2.top()) {
            int u = Q1.top(), v = Q2.top();
            Q1.pop(), Q2.pop(); sum1 += v - u, sum2 += u - v;
            Q1.emplace(v), Q2.emplace(u);
        }
        dp[z][i] = ((i+1ll) * (Q1.top()) - sum1) + (sum2 - (i+1ll) * Q1.top());
    }
}


int main() {
    scanf("%d %d", &k, &n);
    for(int i = 0; i < n; ++i) {
        char a[3], b[3]; int c, d;
        scanf("%s %d %s %d", a, &c, b, &d);
        if(a[0] == b[0]) ans += abs(c - d);
        else vec.emplace_back(c, d);
    }
    sz = vec.size();
    if(!sz) return !printf("%lld\n", ans);
    ans += sz;
    sort(all(vec), [&](const pii &a, const pii &b) {
        return a.x + a.y < b.x + b.y;
    });
    solve_median(0);
    if(k == 1) return !printf("%lld\n", ans + dp[0][sz-1]);
    reverse(all(vec)); solve_median(1);
    long val = dp[0][sz-1];
    for(int i = 0; i < sz-1; ++i) val = min(val, dp[0][i] + dp[1][sz-i-2]);
    return !printf("%lld\n", ans + val);
}