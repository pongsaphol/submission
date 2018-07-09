#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,t,d[205][205],arr[20],dp[15][1<<15];

void read_input(){
	scanf("%d%d%d",&n,&m,&t);
	fill(d[0],d[0]+sizeof(d)/sizeof(int),1e9);
	for(int i = 0;i<t;++i) scanf("%d",arr+i);
	while(m--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		d[u][v] = w;
		d[v][u] = w;
	}
}
void apsp(){
	for(int k = 1;k<=n;++k){
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=n;++j){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

void tsp(){
	fill(dp[0],dp[0]+sizeof(dp)/sizeof(int),1e9);
	for(int i = 0;i<t;++i) dp[i][1<<i] = d[1][arr[i]];
	for(int k = 0;k<(1<<t);++k){
		for(int i = 0;i<t;++i){
			for(int j = 0;j<t;++j){
				dp[i][k|(1<<i)] =min(dp[i][k|(1<<i)], dp[j][k] + d[arr[i]][arr[j]]);
			}
		}
	}
}

int solve(){
	apsp();
	tsp();
	int mn = 1e9;
	for(int i = 0;i<t;++i){
		mn = min(mn, dp[i][(1<<t)-1] + d[arr[i]][n]);
	}
	return mn;
}

int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%d\n",solve());
}