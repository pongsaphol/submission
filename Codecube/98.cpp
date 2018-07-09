#include <cstdio>
#include <algorithm>
using namespace std;

int time_[1000005];
int arr[1000005];

int main(){
	//freopen("r","r",stdin);
	int n,m;
	int cnt = 0;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i)scanf("%d",arr+i);
	for(int i = 1;i<=m;++i){
		int now;
		scanf("%d",&now);
		if(i-time_[now]>=arr[now]){
			cnt++;
			time_[now] = i;
		}
	}
	printf("%d\n",cnt);
}