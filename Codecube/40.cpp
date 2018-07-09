#include <cstdio>
#include <algorithm>
using namespace std;
int M,n;
typedef struct{
	int a,b,c,d;
	bool type;
	
}X;
X t(X a,X b){
		int _a = a.a*b.c+a.b*b.b+a.c*b.a;
		int _b = a.a*b.d+2*a.b*b.a+a.c*b.b;
		int _c = 3*a.a*b.a+a.b*b.d+a.c*b.c;
		int _d = 3*a.a*b.b+2*a.b*b.c+a.c*b.d;
		return {_a%M,_b%M,_c%M,_d%M,true};
	}
	X exp(const X &a){
		if(a.type){
			int _a = 2*(a.a*a.d+a.b*a.c);
			int b = 2*(2*a.a*a.c+a.b*a.d);
			int c = 2*(3*a.a*a.b+a.c*a.d);
			int d = 6*a.a*a.a+3*a.b*a.b+2*a.c*a.c+a.d*a.d;
			return {_a%M,b%M,c%M,d%M,true};
		}else{
			// printf("bug\n");
			// printf("%d %d %d %d\n",a.a,a.b,a.c,a.d);
			int _a = 2*a.a*a.b;
			int b = 2*a.a*a.c;
			int c = 2*a.b*a.c;
			int d = 3*a.a*a.a+2*a.b*a.b+a.c*a.c;
			return {_a%M,b%M,c%M,d%M,true};
		}
	}
X first;
X divide(int pw){
	if(pw == 1)return first;
	X now = divide(pw/2);
	now=exp(now);
	if(pw%2)now=t(first,now);
	return now;
}
void read_input(){
	int a,b,c,h;
	scanf("%d%d%d%d%d",&a,&b,&c,&n,&h);
	first = {a,b,c,0,false};
	M = h;
}

void solve(){
	if(n==1){
		printf("0 %d %d %d\n",first.a%M,first.b%M,first.c%M);
		return;
	}
	X now = divide(n);
	printf("%d %d %d %d\n",now.a,now.b,now.c,now.d);
}

int main(){
	//freopen("r","r",stdin);
	int T;scanf("%d",&T);
	while(T--){
		read_input();
		solve();
	}
}