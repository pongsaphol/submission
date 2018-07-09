#include <cstdio>
#include <vector>
#include <algorithm>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

P A[1005],B[1005];

double dis(const P &a,const P &b){
	return sqrt(((long long)a.x-b.x)*(a.x-b.x)+((long long)a.y-b.y)*(a.y-b.y));
}

bool chk[1005];

int main(){
	//freopen("r","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		A[i] = {a,b};
	}
	for(int i = 1;i<=m;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		B[i] = {a,b};
	}
	double mx = 0.0;
	for(int i = 1;i<=n;++i){
		double mn = 4e9;
		for(int j = 1;j<=m;++j){
			double d = dis(A[i],B[j]);
			mn = min(mn,d);
		}
		mx = max(mx,mn);
	}
	printf("%.4f\n",mx);
}
