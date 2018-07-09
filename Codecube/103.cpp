#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1000005];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		dp[a]++;
		dp[b+1]--;
	}
	int st = -1,ed = -1;
	for(int i = 0;i<=1000000;++i){
		if(i!=0)dp[i]+=dp[i-1];
		if(dp[i] == n){
			if(st == -1){
				st = i;
				ed = i;	
			}else{
				ed = i;
			}
		}
	}
	if(st == -1){
		printf("-1\n");
		return 0;
	}
	if(m >= st && m <= ed){
		printf("%d\n", 0);
	}else if(m < st){
		printf("%d\n", st-m);
	}else if(m > ed){
		printf("%d\n", m-ed);
	}
}