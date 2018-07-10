#include "dreaming.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
 
const int N = 1e5+5, INF = 1e9+1;
 
vector<pii> g[N];
bool check[N];
int Answer;
pii Max1[N], Max2[N];
 
void dfs(int u, int p) {
    check[u] = true;
    for(pii v : g[u]) if(v.x != p) {
        dfs(v.x, u);
        pii ret(Max1[v.x].x + v.y, v.x);
        if(ret > Max1[u]) swap(ret, Max1[u]);
        if(ret > Max2[u]) swap(ret, Max2[u]);
    } 
    Answer = max(Answer, Max1[u].x + Max2[u].x);
} 
 
void find(int u, int p, int d, int &ret) {
    int now = max(Max1[u].x, d);
    if(now < ret) ret = now;
    for(pii v : g[u]) if(v.x != p) 
        find(v.x, u, max(d, Max1[u].y == v.x ? Max2[u].x : Max1[u].x) + v.y, ret);
}
 
int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    for(int i = 0; i < M; ++i) {
        g[A[i]].emplace_back(B[i], T[i]);
        g[B[i]].emplace_back(A[i], T[i]);
    }
    vector<int> V;
    for(int i = 0; i < N; ++i) if(!check[i]) {   
        dfs(i, -1); 
        int shortest = INF;
        find(i, -1, 0, shortest);
        V.emplace_back(shortest);
    }
    sort(V.begin(), V.end(), greater<int>());
    if(V.size() >= 2) Answer = max(Answer, V[0] + V[1] + L);
    if(V.size() >= 3) Answer = max(Answer, V[1] + V[2] + L + L);
    return Answer;
}
