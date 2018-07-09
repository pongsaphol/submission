#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
#include <queue>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e3+5;
int n,arr[MAXN][MAXN];
int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};
bool check[MAXN][MAXN];
P st,ed;

void read_input(){
	scanf("%d",&n);
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=n;++j){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==0){
				if(st.x==0)st = {i,j};
				else ed = {i,j};
			}
		}
	}
}

bool f(int m){
	memset(check,0,sizeof check);
	queue<P> Q;
	Q.push(st);
	while(!Q.empty()){
		P now = Q.front();
		Q.pop();
		if(check[now.x][now.y])continue;
		if(now==ed)return true;
		check[now.x][now.y] = true;
		for(int i = 0;i<4;++i){
			P d = {now.x+x[i],now.y+y[i]};
			if(d.x<1||d.x>n||d.y<1||d.y>n||arr[d.x][d.y]>m)continue;
			Q.push(d);
		}
	}
	return false;
}

long long solve(){
	int L = 1,R = 1e6,mid;
	while(L<R){
		mid = (L+R)/2;
		if(f(mid))R = mid;
		else L = mid+1;
	}
	//return R;
}

int main(){
	freopen("r","r",stdin);
	read_input();	
	printf("%lld\n",solve());
}