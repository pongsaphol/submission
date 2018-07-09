#include <cstdio>
#include <algorithm>
#define long long long
using namespace std;

const int MAXN = 1e6+5;
int n,arr[MAXN];
long dp[MAXN][3];

void read_input(){
	scanf("%d",&n);
	for(int i = 1;i<=n;++i){
		scanf("%d",arr+i);
	}
}

long solve(){
	for(int i = 1;i<=n;++i){
		for(int j = 0;j<=2;++j){
			if(j == 0){
				if(i%2)dp[i][j] = dp[i-1][j] - arr[i];
				else dp[i][j] = dp[i-1][j] + arr[i];
			}else if(j == 1){
				if(i%2)dp[i][j] = min(dp[i-1][j]+arr[i],dp[i-1][j-1]-arr[i]);
				else dp[i][j] = min(dp[i-1][j]-arr[i],dp[i-1][j-1]+arr[i]);
			}else{
				if(i%2)dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])-arr[i];
				else dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+arr[i];
			}
		}
	}
	return min(dp[n][0],min(dp[n][1],dp[n][2]));
}

int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%lld\n",solve());
}