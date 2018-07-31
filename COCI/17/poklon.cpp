#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 5e5+5;

int n, m, A[N], t[N], ans[N];
vector<pii> que[N];

void update(int x, int v) {
    for(; x; x -= x & -x) t[x] += v;
}

int query(int x) {
    int sum = 0;
    for(; x <= n; x += x & -x) sum += t[x];
    return sum;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    for(int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        que[b].emplace_back(a, i);
    }
    map<int, deque<int> > M;
    for(int i = 1; i <= n; ++i) {
        if(M[A[i]].empty()) M[A[i]].push_back(0);
        if(M[A[i]].size() == 3) {
            update(M[A[i]][0], 1), update(M[A[i]][1], -1);
            M[A[i]].pop_front();
        }
        M[A[i]].push_back(i);
        if(M[A[i]].size() == 3) 
            update(M[A[i]][0], -1), update(M[A[i]][1], 1);
        for(pii z : que[i]) ans[z.y] = query(z.x);
    }
    for_each(ans, ans+m, [](int x) { printf("%d\n", x); });
}