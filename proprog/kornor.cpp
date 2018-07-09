#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

int n, ans[105], mod = 1e9+7;

int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &n);
	priority_queue<P, vector<P>, greater<P> > Q;
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		Q.push({x, i});
	}	
	int z = 2;
	for(int i = 1; i <= 100000000; ++i) {
		if(!Q.empty()) if(Q.top().x == i) {
			ans[Q.top().second] = z-1;
			Q.pop();
		}
		z = (z<<1)%mod;
	}
	for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]); 	
}