#include <cstdio>
#include <algorithm>
using namespace std;

bool A[105];

int main() {
	// freopen("r", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		A[x] = true;
	}
	int cnt = 0;
	for(int i = 0; i < m; ++i) {
		if(!A[i]) cnt++;
	}
	if(A[m]) cnt++;
	printf("%d\n", cnt); 
}