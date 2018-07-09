#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 997;

typedef struct matrix
{
	int a,b,c,d;
}matrix;
matrix _(const matrix &x,const matrix &y){
	matrix now;
	now.a = (x.a*y.a+x.b*y.c)%mod;
	now.b = (x.a*y.b+x.b*y.d)%mod;
	now.c = (x.c*y.a+x.d*y.c)%mod;
	now.d = (x.c*y.b+x.d*y.d)%mod;
	return now;
}
matrix start = {0,1,4,3};

matrix _divide(int lv){
	if(lv==1)return start;
	matrix now = _divide(lv/2);
	if(lv%2)return _(_(now,now),start);
	return _(now,now);
}

int solve(){
	int n;
	scanf("%d",&n);
	if(n==0)return 3;
	matrix now = _divide(n);
	return (now.a*3+now.b*2)%mod;
}
int main(){
	// freopen("r","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)printf("%d ",solve());
}