#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define P pair<int,int>
#define x first
#define y second
using namespace std;
typedef struct node {
    int w,u;
    bool st;
    friend inline bool operator<(const struct node &a,const struct node &b){
        return a.w>b.w;
    }
}node;
typedef struct vertex {
    int v,w,idx;
}vertex;
vector<vertex> g[1005];
int n,m,d[2][1005];
int dijk(int x){
    fill(d[0],d[0]+sizeof(d)/sizeof(int),(int)1e9);
    d[1][1] = 0;
    priority_queue<node> Q;
    Q.push({0,1,1});
    while(!Q.empty()){
        int cx = Q.top().w;
        int u = Q.top().u;
        int st = Q.top().st;
        Q.pop();
        if(cx!=d[st][u])continue;
        for(auto now:g[u])if (now.idx<=x){
            int v = now.v,w = now.w;
            //printf("%d %d %d %d\n", u, st, v, !st);
            if(d[st][u]+w<d[!st][v]){
            //printf("%d %d %d %d\n", u, st, v, !st);
                d[!st][v] = d[st][u]+w;
                Q.push({d[!st][v],v,!st});
            }
        }
    }
    /*for(int i = 1;i<=n;++i){
        printf("%d->%d %d\n",i,d[0][i],d[1][i]);
    }*/
    return d[0][n];
}
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
    }
    int ans2 = dijk(m);
    int L = 1,R = m,mid;
    while(L<R){
        mid = (L+R)/2;
        if(dijk(mid)>ans2)L = mid+1;
        else R = mid;
    }
    printf("%d %d\n",L,ans2);
}
