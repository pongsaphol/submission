#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

const int MAXN = 1e6+5;
int n,FT[MAXN],arr[MAXN],ans[MAXN],cache[MAXN],idx = 1;
void update(int idx,int val){
	while(idx<=1e6){
		FT[idx] += val;
		idx+=idx&(-idx);
	}
}

int query(int idx){
	int val = 0;
	while(idx>=1){
		val+=FT[idx];
		idx-=idx&(-idx);
	}
	return val;
}
void read_input(){
	scanf("%d",&n);
	vector<pair<int,int> > V;
	V.reserve(1e6);
	for(int i = 1;i<=n;++i){
		scanf("%d",arr+i);
		V.push_back({arr[i],i});
	}
	sort(V.begin(),V.end());
	arr[V[0].second] = 1;
	for(int i = 1;i<n;++i){
		if(V[i].first!=V[i-1].first)idx++;
		arr[V[i].second] = idx;
	}
}

void solve(){
	int now = 0;
	for(int i = 1;i<=n;++i){
		while(arr[cache[now]]<=arr[i]&&now!=0){
			update(1,-1);update(arr[cache[now]],1);
			now--;
		}
		//printf("%d %d\n",i,now);
		ans[i]+=i-cache[query(arr[i])];
		cache[++now] = i;
		update(1,1);update(arr[i],-1);
	}
	memset(FT,0,sizeof FT);
	now = 0;
	cache[0] = n+1;
	for(int i = n;i>=1;--i){
		while(arr[cache[now]]<=arr[i]&&now!=0){
			update(1,-1);
			update(arr[cache[now]],1);
			now--;
		}
		ans[i]+=cache[query(arr[i])]-i;
		cache[++now] = i;
		update(1,1);
		update(arr[i],-1);
	}
	for(int i = 1;i<=n;++i){
		printf("%d ",ans[i]-1);
	}
	printf("\n");
}
int main(){
	//freopen("r","r",stdin);
	read_input();
	solve();
}