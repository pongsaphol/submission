#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 3e4+5;
vector<int> g[MAXN],ans;

void dfs(int u, int p){
	if(g[u].size() == 1) ans.push_back(u);
	else for(auto v:g[u]) if(v != p) dfs(v,u);
}

int main(){
	//freopen("r","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	int root = 0;
	if(n==2){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("1\n%d %d\n",a,b);
		return 0;
	}
	for(int i = 1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
		if(g[a].size()>1)root = a;
		if(g[b].size()>1)root = b;
	}
	dfs(root,-1);
	int sz = (ans.size()+1)/2;
	printf("%d\n",sz);
	if(m == 2){
		if(ans.size()%2){
			printf("%d %d\n",ans[ans.size()/2], root);
		}
		for(int i = 0;i<ans.size()/2;++i){
			printf("%d %d\n",ans[i],ans[i+sz]);
		}
	}
}