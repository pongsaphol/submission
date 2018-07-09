#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

const int MAXN = 1005;

int n,m,s,t,d[MAXN];
vector<P> g[MAXN];

int A,B,C,D;
void read_input(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	scanf("%d%d%d%d",&A,&B,&C,&D);
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
	}
}

void dijkstra(){
	priority_queue<P,vector<P>,greater<P> > Q;
	d[s] = 0;
	Q.push({d[s],s});
	while(!Q.empty()){
		P now = Q.top();
		Q.pop();
		if(now.x != d[now.y]) continue;
		int u = now.y;
		for(auto i:g[u]){
			int v = i.x, w = i.y;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v],v});
			}
		}
		if(u == A && d[u] <= D){
			if(d[B] > d[u] + C){
				d[B] = d[u] + C;
				Q.push({d[B],B});
			}
		}
	}
}

int solve(){
	fill(d,d+MAXN,1e9);
	dijkstra();
	return d[t];
}

int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%d\n",solve());
}