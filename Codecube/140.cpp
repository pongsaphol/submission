#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1e6+5;

int n,m,cnt[MAXN];
priority_queue<int,vector<int>,greater<int> > Q[MAXN];

void read_input(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			int now;scanf("%d",&now);
			Q[i].push(now);
		}
	}
}

int solve(){
	for(int i = 1;i<=m;++i){
		int mx = 0,idx = 0;
		for(int j = 1;j<=n;++j){
			int now = Q[j].top();Q[j].pop();
			if(now>mx){
				mx = now;
				idx = j;
			}
		}
		cnt[idx]++;
	}
	int mx = 0,idx = 0;
	for(int i = 1;i<=n;++i){
		if(cnt[i]>mx){
			mx = cnt[i];
			idx = i;
		}
	}
	return idx;
}

int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%d\n",solve());
}