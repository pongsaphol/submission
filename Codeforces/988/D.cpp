#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 2e5+5;

long long inf = 1e9;
int n, A[N];
int bck[N][30];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A + i);
	sort(A + 1, A + n + 1);
	pii mx(0, 0);
	for(int i = 1; i <= n; ++i) for(int j = 0; j <= 30; ++j) {
		long long z = (long long)A[i] - (1ll << j);
		if(z < -inf) continue;
		int* l = lower_bound(A+1, A + n + 1, A[i] - (1 << j));
		if(*l != (A[i] - (1 << j))) continue;
		int idx = l - A;
		if(bck[idx][j] != 0) {
			puts("3");
			return !printf("%d %d %d\n", A[i], A[idx], A[bck[idx][j]]);
		}
		bck[i][j] = idx;
		mx = pii(i, j); 
	}
	if(mx.x == 0) {
		puts("1");
		return !printf("%d\n", A[1]);
	}
	printf("2\n%d %d\n", A[mx.x], A[bck[mx.x][mx.y]]);
}