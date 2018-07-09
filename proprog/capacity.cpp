#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 5e4-1;
int n,arr[10005],dp[2][10005];

void scan(){
	scanf("%d",&n);
	for(int i = 1;i<=n;++i)scanf("%d",arr+i);
}

int solve(){
	dp[2&1][1] = -1;
	dp[2&1][2] =  1;
	for(int i = 3;i<=n;++i){
		for(int j = 1;j<=i;++j){
			dp[i&1][j] = (i-j)*dp[(i-1)&1][j]+(j-1)*dp[(i-1)&1][j-1];
			dp[i&1][j] %= mod;
		}
	}
	int sum = 0;
	for(int i = 1;i<=n;++i){
		sum+=(dp[n&1][i]*(long long)(arr[i]))%mod;
		sum%=mod;
	}
	return sum;
}
int main(){
	//freopen("_.in","r",stdin);
	scan();
	printf("%d",solve());
}