#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+5;
int n,k,p,arr[MAXN];
int mn = 1e9;
void read_input(){
	scanf("%d%d%d",&n,&k,&p);
	for(int i = 1;i<=n;++i){
		scanf("%d",arr+i);
		mn = min(mn,arr[i]);
	}
}

int solve(){
	int L = mn,R = 1e9,mid;
	while(L<R){
		mid = (L+R)/2;
		int cnt = 0;
		for(int i = 1;i<=n;++i){
			if(arr[i]>mid){
				cnt++;
				i+=p-1;
			}
		}
		if(cnt>k){
			L = mid+1;
		}else{
			R = mid;
		}
	}
	return L;
}

int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%d\n",solve());
}