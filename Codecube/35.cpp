#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5+5;
vector<int> g[MAXN],x[MAXN];
int n,m,k,arr[MAXN],level[MAXN];
bool check[MAXN];
void read_input(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=n;++i)scanf("%d",arr+i);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

void bfs(){
	fill(level,level+MAXN,1e9);
	queue<int> Q;
	Q.push(k);
	level[k] = 0;
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		if(check[now])continue;
		check[now] = true;
		for(auto i:g[now]){
			level[i] = min(level[i], level[now]+1);
			Q.push(i);
		}
	}
}

long long solve(){
	bfs();
	for(int i = 1;i<=n;++i){
		if(level[i] == 1e9) x[n].push_back(arr[i]);
		else x[level[i]].push_back(arr[i]);
	}
	long long sum = 0;
	priority_queue<int> Q;
	for(int i = n;i>=1;--i){
		for(auto j:x[i]){
			Q.push(j);
		}
		if(!Q.empty()&&Q.top()>=0){
			sum+=Q.top();
			Q.pop();
		}
	}
	return sum;
}

int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%lld\n",solve());
}