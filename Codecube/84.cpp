#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
const int MAX = 1e5;
vector<pii> g[MAX+5];
int nodenum[MAX+5],s,r,t;
bool chk[MAX+5];
long long sum = 0;

long long dfs(int idx,int prev){
	if(idx==r){
		long long now = chk[idx]?0:nodenum[idx];
		chk[idx] = true;
		return now;
	}
	for(int i = 0;i<g[idx].size();++i){
		if(g[idx][i].first==prev)continue;
		long long now = dfs(g[idx][i].first,idx);
		if(now!=LLONG_MIN){
			now += (chk[idx]?0:nodenum[idx])-g[idx][i].second;
			chk[idx] = true;
			return now;
		}
	}
	return LLONG_MIN;
}

long long dfs1(int idx,int prev){
	if(chk[idx]){
		for(int i = 0;i<g[idx].size();++i){
			if(g[idx][i].first==prev)continue;
			sum+=dfs1(g[idx][i].first,idx);
		}
		return 0;
	}
	long long now = nodenum[idx];
	for(int i = 0;i<g[idx].size();++i){
		if(g[idx][i].first == prev){
			now -= 2ll*g[idx][i].second;
			continue;
		}
		now+=dfs1(g[idx][i].first,idx);
	}
	if(now>0)return now;
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<n;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(pii(v,w));
		g[v].push_back(pii(u,w));
	}
	for(int i = 1;i<=n;++i){
		scanf("%d",nodenum+i);
	}
	scanf("%d%d%d",&s,&t,&r);
	sum+=dfs(s,s)+dfs(t,t);
	dfs1(s,s);
	printf("%lld",sum);
}
