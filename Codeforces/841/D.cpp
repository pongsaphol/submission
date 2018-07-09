#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

const int MAXN = 3e5 + 5;

int n, m, arr[MAXN], deg[MAXN];
vector<P> E;
int main() {
	freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n; ++i)scanf("%d", arr + i);
	while(m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		E.push_back({u, v});
		deg[u] ++;
		deg[v] ++;
	}
	queue<int> Q;
	for(int i = 0; i < E.size(); ++i) {
		int u = E[i].x;
		int v = E[i].y;
		bool st = true;
		if(arr[u] != -1 && deg[u]%2 != arr[u] && arr[v] != -1 && deg[v]%2 != arr[v]) st = false;
		//if() st = false;
		if(st) Q.push(i + 1);
	}
	printf("%d\n", Q.size());
	while(!Q.empty()) {
		printf("%d\n", Q.front());
		Q.pop();
	}
}