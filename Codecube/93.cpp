#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <utility>
#define x first
#define y second
#define P pair<int,int>
using namespace std;

P A[1005];
float slove[1005][1005];
int n,a,b;
void read_input(){
	scanf("%d",&n);
	for(int i = 1;i<=n;++i){
		scanf("%d%d",&a,&b);
		A[i] = {a,b};
	}
}

int solve(){
	int cnt = 0;
	for(int i = 1;i<=n;++i){
		for(int j = i+1;j<=n;++j){
			for(int k = j;k<=n;++k){
				if(slove[i][j]!=slove[i][k])cnt++;
			}
		}
	}
	return cnt;
}
void build(){
	for(int i = 1;i<=n;++i){
		for(int j = i+1;j<=n;++j){
			float d1 =(A[i].x-A[j].x);
			float d2 = (A[i].y-A[j].y);
			if(d2!=0)slove[i][j] = d1/d2;
			else slove[i][j] = 1e9;
		}
	}
}

int main(){
	//freopen("_.in","r",stdin);
	read_input();
	build();
	printf("%d\n",solve());
}