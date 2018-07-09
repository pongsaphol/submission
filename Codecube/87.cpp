#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1000005];
int arr[1000005];

int main(){
	//freopen("r","r",stdin);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1;i<=n;++i){
		scanf("%d",arr+i);
		dp[arr[i]]++;
	}
	long long sum = 0;
	for(int i = 1;i<=n;++i){
		dp[arr[i]]--;
		int re = k-arr[i];
		sum+=dp[re];
	}
	printf("%lld\n",sum);
}
