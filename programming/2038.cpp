#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

const int MAXN = 205;

int n,m,d[MAXN],chk[MAXN];
vector<P> g[MAXN];
void read_input(){
	scanf("%d%d",&n,&m);
}

void kruskal(){
	fill(d,d+MAXN,1e9);
	memset(chk,0,sizeof chk);
	priority_queue<P,vector<P>,greater<P> > Q;
	d[1] = 0;
	Q.push({d[1],1});
	while(!Q.empty()){
		P now = Q.top();
		Q.pop();
		if(now.x != d[now.y]) continue;
		int u = now.y;
		chk[u] = true;
		for(auto i:g[u]){
			int v = i.x, w = i.y;
			if(d[v]>w&&!chk[v]){
				d[v] = w;
				Q.push({d[v],v});
			}
		}
	}
}

int solve(){
	int u,v,w;
	scanf("%d%d%d",&u,&v,&w);
	g[u].push_back({v,w});
	g[v].push_back({u,w});
	kruskal();
	int sum = 0;
	for(int i = 1;i<=n;++i){
		if(d[i] == 1e9) return -1;
		sum+=d[i];
		//printf("%d::%d\n",i,d[i]);
	}
	return sum;
}

int main(){
	freopen("r","r",stdin);
	read_input();
	while(m--)printf("%d\n",solve());
}