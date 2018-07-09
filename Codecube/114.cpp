#include <cstdio>

int solve(){
	int a,b;
	scanf("%d%d",&a,&b);
	int sum = 0;
	for(int i = 0;i<=10000;++i){
		int time = b-20*i;
		if(time>a)continue;
		if(time<0)break;
		sum++;
	}
	return sum;
}

int main(){
	//freopen("r","r",stdin);
	int T;scanf("%d",&T);
	for(int i = 1 ; i <= T;++i){
		printf("Case #%d: %d\n",i,solve());
	}
}