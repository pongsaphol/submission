#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e3+5;
int n,m,arr[MAXN];

void read_input(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i)scanf("%d",arr+i);
}

int solve(){
	int L = 1,R = 2e9,mid;
	while(L<R){
		mid = ((size_t)L + R)/2;
		int sum = 0,cnt = 1;
		for(int i = 1;i<=n;++i){
			if(arr[i]>mid){
				cnt = 1e9;
			}
			if(sum+arr[i]>mid){
				cnt++;
				sum = arr[i];
			}else{
				sum+=arr[i];
			}
		}
		if(cnt>m){
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