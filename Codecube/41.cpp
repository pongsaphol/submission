#include <cstdio>
#include <algorithm>
#define long long long
using namespace std;

const int MAXN = 1e6+5;
int n,m,arr[MAXN];

void read_input(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i) scanf("%d",arr+i);
}

long solve(){
	long low,up;
	long L = 1,R = 1e12+1,mid;
	while(L<R){
		mid = (L+R)/2;
		int cnt = 1;
		long pow = mid;
		for(int i = 1;i<=n;++i){
			if(pow-arr[i]>=0){
				pow-=arr[i];
			}else{
				cnt++;
				pow = mid;
				if(pow-arr[i]<0){
					cnt = 1e9;
				}else{
					pow-=arr[i];
				}
			}
		}
		//printf("%lld, %d\n",mid,cnt);
		if(cnt<=m) R = mid;
		else L = mid+1;
	}
	low = R;
	L = 1,R = 1e12+1,mid;
	while(L<R){
		mid = (L+R+1)/2;
		int cnt = 1;
		long pow = mid;
		for(int i = 1;i<=n;++i){
			if(pow-arr[i]>=0){
				pow-=arr[i];
			}else{
				cnt++;
				pow = mid;
				if(pow-arr[i]<0){
					cnt = 1e9;
				}else{
					pow-=arr[i];
				}
			}
		}
		if(cnt>=m) L = mid;
		else R = mid-1;
	}
	up = L;
	if(up == 1e12+1)return -1;
	else return up-low+1;
	//printf("%lld %lld\n",low,up);
}

int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%lld\n",solve());
}