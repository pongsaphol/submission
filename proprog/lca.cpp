#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> g[1005];

int anc[1005][12];/// anc[i][j] = 2^j of i node
int level[1005];/// level from root

void dfs(int node,int par,int lv){
    level[node] = lv;
    anc[node][0] = par;
    for(int i = 1;i<10;++i)
        anc[node][i] = anc[anc[node][i-1]][i-1];
    for(auto now:g[node]){
        if(now!=par)dfs(now,node,lv+1);
    }
}

int lca(int x,int y){
    if(level[x]<level[y])swap(x,y);
    for(int i = 10;i>=0;--i)
        if(level[anc[x][i]]>=level[y])x = anc[x][i];
    if(x==y)return x;
    for(int i = 10;i>=0;--i){
        if(anc[x][i]!=anc[y][i]){
            x = anc[x][i],y = anc[y][i];
        }
    }
    return anc[x][0];
}
int main(){
    int T;scanf("%d",&T);
    int oT = T;
    while(T--){
        memset(level,0,sizeof level);
        memset(anc,0,sizeof anc);
        for(int i = 0;i<=1001;++i)g[i].clear();
        printf("Case %d:\n",oT-T);
        int n;scanf("%d",&n);
        int x = 0;for(int i = 1;i<=n;++i)x^=i;
        for(int i = 1;i<=n;++i){
            int t;scanf("%d",&t);
            while(t--){
                int k;scanf("%d",&k);
                x^=k;
                g[i].push_back(k);
                g[k].push_back(i);
            }
        }
        dfs(x,0,1);
        int _t;scanf("%d",&_t);
        while(_t--){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",lca(a,b));
        }
    }
}
