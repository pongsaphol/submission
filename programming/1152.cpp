#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define P pair<int,int> 
#define x first
#define y second
using namespace std;

const int MAXN = 1e3+5;
int n;
vector<int> g[1000005];

void read_input(){
	scanf("%d",&n);
	int now;
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			scanf("%d",&now);
			g[i+j].push_back(now);
		}
	}
}

int solve(){
	int st = n+n-1;
	int sum = 0;
	priority_queue<int> Q;
	while(--st>=1){
		for(auto now:g[st]){
			Q.push(now);
		}
		if(!Q.empty()){
			sum+=Q.top();
			Q.pop();
		}
	}
	return sum;
}

int main(){
	//freopen("_.in","r",stdin);
	read_input();
	printf("%d\n",solve());
}