#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 1e5+105;
const int inf = 2e9+1;
int n,k,p,qs[MAXN],dp[2][MAXN];

void read_input(){
	scanf("%d%d%d",&n,&k,&p);
	for(int i = 1;i<=n;++i){
		scanf("%d",qs+i);
		qs[i]+=qs[i-1];
	}
}

int solve(){
	if(k*p>=n)return qs[n];
	for(int i = 1;i<=k;++i){
		for(int j = 0;j<p;++j)dp[i&1][j] = -inf;
		for(int j = p;j<=n;++j){
			dp[i&1][j] = max(dp[i&1][j-1],dp[(i-1)&1][j-p]+qs[j]-qs[j-p]);
		}
	}
	
	return dp[k&1][n];
}

int main(){
	//freopen("_.in","r",stdin);
	read_input();
	printf("%d\n",solve());
}