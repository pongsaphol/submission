#include <cstdio>
#include <algorithm>
#define P pair<int,int>
#define x first
#define y second
using namespace std;
int n,dp[16][1<<16];
P g[20],st;
void read_input(){
	int a,b;
	scanf("%d%d",&a,&b);
	st = {a,b};
	scanf("%d",&n);
	for(int i = 0;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		g[i] = {x,y};
	}
}

int d(const P &i,const P &j){
	return abs(i.x-j.x)+abs(i.y-j.y);
}
void minby(int &x,int y){
	x = min(x,y);
}
void tsp(){
	for(int k = 0;k<(1<<n)-1;++k)
	for(int i = 0;i<n;++i)
	for(int j = 0;j<n;++j)
		minby(dp[i][k|(1<<i)],dp[j][k]+d(g[i],g[j]));
}

int solve(){
	fill(dp[0],dp[0]+sizeof(dp)/sizeof(int),1e9);
	for(int i = 0;i<n;++i){
		dp[i][1<<i] = d(st,g[i]);
	}
	tsp();
	int mn = 1e9;
	for(int i = 0;i<n;++i){
		minby(mn,dp[i][(1<<n)-1]+d(g[i],st));
	}
	if(mn==1e9)mn = 0;
	return mn;
}

int main(){
	freopen("_.in","r",stdin);
	read_input();
	printf("%d",solve());
}