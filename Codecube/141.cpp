#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1e5+5;

int n,w,k,arr[MAXN],dp[MAXN];

void read_input(){
	scanf("%d%d%d",&n,&w,&k);
	for(int i = 1;i <= n; ++i){
		scanf("%d",arr+i);
	}
}

bool f(int M){
	memset(dp,0,sizeof(dp));
	int cnt = 0;
	for(int i = 1;i<=n;++i){
		dp[i]+=dp[i-1];
		int g = arr[i]-M;
		if(g>dp[i]){
			int l = g-dp[i];
			cnt += l;
			dp[i] += l;
			dp[i+w] -= l;
		}
	}
	if(cnt<=k)return true;
	return false;
}

int solve(){
	int L = 0,R = 1e9,mid;
	while(L<R){
		int mid = (L+R)/2;
		if(f(mid))R = mid;
		else L = mid+1;
	}
	return R;
}

int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%d\n",solve());
}