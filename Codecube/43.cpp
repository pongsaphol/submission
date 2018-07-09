#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#define P pair<int,int> 
#define x first
#define y second
using namespace std;

typedef struct node{
	int u,c,w;
}node;

const int MAXN = 305,MAXK = 2e3+5;
vector<node> g[MAXN];
int n,m,k,s,t,dp[MAXN][MAXK];

void read_input(){
	scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
	for(int i = 0;i<m;++i){
		int u,v,c,w;
		scanf("%d%d%d%d",&u,&v,&c,&w);
		g[u].push_back({v,c,w});
		g[v].push_back({u,c,w});
	}
}

int solve(){
	fill(dp[0],dp[0]+sizeof(dp)/sizeof(int),-2e9-1);
	dp[s][0] = 0;
	for(int i = 1;i<=k;++i){
		for(int j = 1;j<=n;++j){
			for(auto &now:g[j]){
				if(i-now.w<0)continue;
				dp[j][i] = max(dp[j][i],dp[now.u][i-now.w]+now.c);
			}
		}
	}
	int mx = -2e9-1;
	for(int i = 0;i<=k;++i){
		mx = max(mx,dp[t][i]);
	}
	if(mx <0	) printf("Impossible\n");
	else printf("%d\n",mx);
}

int main(){
//	freopen("r","r",stdin);
	read_input();
	solve();
}