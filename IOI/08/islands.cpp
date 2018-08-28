#include <bits/stdc++.h>
#define long long long 
#define pii pair<long, long>
#define x first
#define y second
using namespace std;

const int N = 1e6+5;

int n, deg[N];
long Answer, MaxAll[N];
pii par[N], MaxIn[N];

void solve(int p) {
    vector<pii> V;
    while(deg[p]) V.emplace_back(p, par[p].y), deg[p]--, p = par[p].x;
    int s = V.size();
    deque<pii> Q;
    long dis = V[0].y, pdis = 0, mx = 0;
    for(auto x : V) mx = max(mx, MaxAll[x.x]), mx = max(mx, MaxIn[x.x].x + MaxIn[x.x].y);
    for(int i = 1; i < s; ++i) {
        while(!Q.empty() && Q.back().x < dis + MaxIn[V[i].x].x) Q.pop_back();
        Q.push_back(pii(dis + MaxIn[V[i].x].x, i));
        dis += V[i].y;
    }
    mx = max(mx, MaxIn[V[0].x].x + Q.front().x);
    for(int i = 0; i < s-1; ++i) {
        if(Q.front().y == i+1) Q.pop_front();
        while(!Q.empty() && Q.back().x < dis + MaxIn[V[i].x].x) Q.pop_back();
        Q.push_back(pii(dis + MaxIn[V[i].x].x, i));
        dis += V[i].y, pdis += V[i].y;
        mx = max(mx, MaxIn[V[i+1].x].x + Q.front().x - pdis); 
    }
    Answer += mx;
}

int main() {
    scanf("%d", &n);
    for(int i = 1, a, b; i <= n; ++i) {
        scanf("%d %d", &a, &b);
        par[i] = pii(a, b);
        deg[a]++;
    }
    queue<int> Q;
    for(int i = 1; i <= n; ++i) if(!deg[i]) Q.emplace(i);
    while(!Q.empty()) {
        int now = Q.front(); Q.pop();
        int p = par[now].x, w = par[now].y;
        MaxAll[now] = max(MaxAll[now], MaxIn[now].x + MaxIn[now].y);
        MaxAll[p] = max(MaxAll[p], MaxAll[now]);
        long ret = MaxIn[now].x + w;
        if(ret > MaxIn[p].x) swap(ret, MaxIn[p].x);
        if(ret > MaxIn[p].y) swap(ret, MaxIn[p].y);
        if(!--deg[p]) Q.emplace(p);
    }
    for(int i = 1; i <= n; ++i) if(deg[i]) solve(i);
    printf("%lld\n", Answer);
}