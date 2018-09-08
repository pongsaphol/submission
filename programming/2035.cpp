#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e2+5,MAXM = 1e4+5;
int N,M,cost[MAXN],weight[MAXM],cache[MAXN];
void read_input(){
	scanf("%d%d",&N,&M);
	for(int i = 1;i<=N;++i){
		scanf("%d",cost+i);
	}
	for(int i = 1;i<=M;++i){
		scanf("%d",weight+i);
	}
}
long long solve(){
	long long sum = 0;
	queue<int> Q;
	for(int i = 1;i<=2*M;++i){
		int now;
		scanf("%d",&now);
		if(now<0){
			now*=-1;
			for(int j = 1;j<=N;++j){
				if(cache[j]==now){
					cache[j] = 0;
					if(!Q.empty()){
						cache[j] = Q.front();
						sum+=weight[Q.front()]*cost[j];
						Q.pop();
					}
					break;
				}
			}
		}else{
			bool st = true;
			for(int j = 1;j<=N;++j){
				if(cache[j]==0){
					cache[j] = now;
					sum+=weight[now]*cost[j];
					st = false;
					break;
				}
			}
			if(st) Q.push(now);
		}
	}
	return sum;
}
int main(){
	//freopen("r","r",stdin);
	read_input();
	printf("%lld\n",solve());
}
