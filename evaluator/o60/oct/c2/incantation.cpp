#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1<<7;

int n, m, A[MAXN], mx;
int chk[MAXN];

void rcsf(int lv) {
	if(lv == n) {
		// for(int i = 0; i < n; ++i) {
		// 	printf("%d ", chk[i]);
		// }
		// printf("\n");
		int sum = 0, now = 0;
		for(int i = 0; i < m; ++i) {
			now = (now<<1) + chk[i];
		}
		// printf("-->%d\n", now);
		sum += A[now];
		// printf("%d\n", sum);
		for(int i = m; i < n; ++i) {
			now = (now<<1) + chk[i] - chk[i-m]*(1<<m);
			sum +=A[now];
		}
		mx = max(mx, sum);
		return;
	}
	chk[lv] = 0;
	rcsf(lv+1);
	chk[lv] = 1;
	rcsf(lv+1);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < (1<<m); ++i) scanf("%d", A+i);
	rcsf(0);
	printf("%d\n", mx);
}