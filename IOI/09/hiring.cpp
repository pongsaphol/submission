#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n;
long w;
vector<pair<int, pii> > V;

int main() {
    scanf("%d %lld", &n, &w);
    for(int i = 1, a, b; i <= n; ++i) {
        scanf("%d %d", &a, &b);
        V.emplace_back(i, pii(a, b));
    }
    sort(V.begin(), V.end(), [&](const pair<int, pii> &a, const pair<int, pii> &b) {
        return 1ll * a.y.x * b.y.y < 1ll * b.y.x * a.y.y;
    });
    long sum = 0;
    priority_queue<pii> Q;
    int mxp = 0, idx;
    pair<long, long> mxv;
    int sz = 0;
    for(int i = 0; i < n; ++i) {
        sum += V[i].y.y, sz++;
        Q.emplace(V[i].y.y, V[i].x);
        while(!Q.empty() && sum * V[i].y.x > w * V[i].y.y) sum -= Q.top().x, Q.pop(), sz--;
        if(sum * V[i].y.x <= w * V[i].y.y) {
            pair<long, long> ret(sum * V[i].y.x, V[i].y.y);
            if(mxp == sz && mxv.x * ret.y > ret.x * mxv.y) mxv = ret, idx = i;
            if(mxp < sz) mxp = sz, idx = i, mxv = ret;
        }
    }
    Q = priority_queue<pii>();
    sum = 0;
    set<int> S;
    for(int i = 0; i <= idx; ++i) {
        sum += V[i].y.y, S.emplace(V[i].x);
        Q.emplace(V[i].y.y, V[i].x);
        while(!Q.empty() && sum * V[i].y.x > w * V[i].y.y) sum -= Q.top().x, S.erase(Q.top().y), Q.pop();
    }
    printf("%d\n", S.size());
    for(auto x : S) printf("%d\n", x);
}