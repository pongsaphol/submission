#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;
int n, m, up[105], down[105], LR[105];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", up + i);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) scanf("%d", LR + j);
		for(int j = 1; j <= n; ++j) scanf("%d", down+j);
		for(int j = 1; j <= n; ++j) 
			 Q.push(3*up[j] + 5*LR[j-1] - 3*down[j] - 5*LR[j]);
		for(int j = 1; j <= n; ++j) up[j] = down[j];
	}
	int sum = 0;
	while(m--) {
		sum += Q.top();
		Q.pop();
	}
	printf("%d\n", sum);
}