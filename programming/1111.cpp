#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define x first
#define y second
#define P pair<int,int>
#define pb push_back
using namespace std;

bool chk[100005];
vector<P> g[100005];
int d[100005];
int mx = 0;
void dfs(int idx){
    mx = max(mx,d[idx]);
    if(chk[idx])return;
    chk[idx] = true;
    //printf("%d %d\n",idx,d[idx]);
    for(auto& now:g[idx]){
        if(!chk[now.x])d[now.x] = d[idx]+now.y;
        dfs(now.x);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].pb(P(v,w));
        g[v].pb(P(u,w));
    }
    dfs(1);
    printf("%d",mx);
}
