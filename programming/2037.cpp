#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

const int MAXN = 2e4+5;
P arr[MAXN];
int n;

void read_input(){
	scanf("%d",&n);
	for(int i = 1;i<=n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		arr[i] = {a,b};
	}
}

int dp[MAXN][2];

int solve(){
	for(int i = 1;i<=n;++i){
		dp[i][1] = min(dp[i-1][0],dp[i-1][1])
	}
}

int main(){
	read_input();
	printf("%d\n",solve());
}