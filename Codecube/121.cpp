#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define long long long
#define P pair<long,int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e5+5;
int n,arr[MAXN];
int d[MAXN];
bool chk[MAXN];
vector<int> g[MAXN];
void read_input(){
	scanf("%d",&n);
	for(int i = 1;i<=n;++i)scanf("%d",arr+i);
	
	
}

long solve(){
	long sum = 0;
	fill(d,d+MAXN,1e9);
	int m;scanf("%d",&m);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		d[b] = min(d[b],arr[a]+arr[b]);
		d[a] = min(d[a],arr[a]+arr[b]);
	}
	for(int i = 2;i<=n;++i)sum+=d[i];
	return sum;
}

int main(){
	freopen("r","r",stdin);
	read_input();
	printf("%lld\n",solve());
}