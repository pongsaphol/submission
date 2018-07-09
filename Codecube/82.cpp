#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define long long long
using namespace std;

const int MAXN = 2e3+5;
int n,m;
long dp[MAXN];

void read_input(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i){
		scanf("%lld",&dp[i]);
		dp[i] += dp[i-1];
	}
}

long solve(){
	long ans = 0ll;
	for(int bit = 43;bit>=0;--bit){
		int memo[MAXN];
		fill(memo,memo+MAXN,1e9);
		memo[0] = 0;
		//printf("-------->%lld\n",ans);
		for(int i = 0;i<=n;++i){
			for(int j = i+1;j<=n;++j){
				long num = dp[j]-dp[i];
				if(!((num&(~ans))>>(bit+1))&&!(num&(1ll<<bit))){
					//if(bit==0) printf("%d %d->%lld\n",i,j,num);
					memo[j] = min(memo[j],memo[i]+1);
				}
			}
		}
		if(memo[n]>m){
			ans|=(1ll<<bit);
		}
	}
	return ans;
}

int main(){
	freopen("r","r",stdin);
	read_input();
	printf("%lld\n",solve());
}