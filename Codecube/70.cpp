#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 2e5+5;

int FT[MAXN],arr[MAXN];

void update(int idx){
	while(idx<=MAXN-5){
		FT[idx]++;
		idx+=idx&(-idx);
	}
}

bool query(int idx){
	int val = 0;
	while(idx>=1){
		val+=FT[idx];
		idx-=idx&(-idx);
	}
	return val>0;
}

int main(){
	freopen("r","r",stdin);
	int n;
	scanf("%d",&n);
	int cnt = 0;
	stack<int> Q;
	for(int i = 1;i<=n;++i){
		int now;
		scanf("%d",&now);
		Q.push(now);
	}
	for(int i = 1;i<=n;++i){
		int now;
		scanf("%d",&now);
		arr[now] = i;
	}
	while(!Q.empty()){
		int now = Q.top();
		Q.pop();
		if(query(now))cnt++;
		update(now);
	}
	printf("%d\n",cnt);
}