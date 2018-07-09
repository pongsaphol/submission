#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct T{
	int r,g,b;
	friend inline T operator+(const T &a,const T &b){
		T now = {a.r+b.r,a.g+b.g,a.b+b.b};
		return now;
	}
}T;

const int MAXN = 1<<20;

T t[MAXN<<1];
int n,m;

int main(){
	//freopen("r","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i){
		int r,g,b;
		r = g = b = 0;
		if(i%3 == 1)r++;
		if(i%3 == 2)g++;
		if(i%3 == 0)b++;
		t[n+i] = {r,g,b};
	}
	for(int i = n-1;i>0;i--) t[i] = t[i<<1] + t[i<<1|1];
	while(m--){
		int x;scanf("%d",&x);
		if(x == 1){
			int a;char B;
			scanf("%d %c",&a,&B);
			int r,g,b;
			r = g = b = 0;
			if(B == 'R')r = 1;
			if(B == 'G')g = 1;
			if(B == 'B')b = 1;
			t[n+a] = {r,g,b};
			for(int i = n+a;i>1;i>>=1)t[i>>1] = t[i]+t[i^1];
		}else{
			int a,b;
			scanf("%d%d",&a,&b);
			b++;
			T sum {0,0,0};
			for(int l = a+n,r = b+n;l<r;l>>=1,r>>=1){
				if(l&1) sum = sum + t[l++];
				if(r&1) sum = sum + t[--r];
			}
			//printf("debug %d %d %d\n",sum.r,sum.g,sum);
			if(sum.r > sum.g && sum.r > sum.b)printf("R\n");
			else if(sum.g > sum.r && sum.g > sum.b)printf("G\n");
			else if(sum.b > sum.r && sum.b > sum.g)printf("B\n");
			else printf("None\n");
		}

	}
}