#include <cstdio>
#include <algorithm>
#define long long long
using namespace std;

const int MAXN = 5e2+5;
int n,m;
long arr[MAXN][MAXN],dp[3][MAXN][55];
void read_input(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			scanf("%lld",arr[i]+j);
		}
	}
}

void maxby(long &a,long b){
	a = max(a,b);
}

long solve(){
	dp[1][1][1] = arr[1][1];
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			for(int k = 0;k<=m;++k){
				maxby(dp[(i+1)%3][j][k+1],dp[i%3][j][k]+arr[i+1][j]);
				maxby(dp[(i+1)%3][j][0],dp[i%3][j][k]);
				maxby(dp[i%3][j+1][k+1],dp[i%3][j][k]+arr[i][j+1]);
				maxby(dp[i%3][j+1][0],dp[i%3][j][k]);
				if(i!=n)dp[i%3][j][k] = 0;
			}
		}
	}
	long ans = 0;
	for(int i = 0;i<=m;++i)maxby(ans,dp[n%3][n][i]);
	return ans;
}

int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%lld\n",solve());
}