#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 1<<19;

int n, par[MAXN][20], dep[MAXN];
long d[MAXN], w[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	long last = 0;
	int cnt = 1;
	while(n--) {
		int met;
		long a, b;
		scanf("%d %lld %lld", &met, &a, &b);
		a ^= last, b ^= last;
		if(met == 1) {
			d[++cnt] = b;
			w[cnt] = b;
			if(w[a] >= w[cnt]) {
				dep[cnt] = dep[a] + 1;
				par[cnt][0] = a;
				d[cnt] += d[a];
			} else {
				int p = a;
				for(int i = 19; i >= 0; --i) {
					if(par[p][i] != 0) if(w[p] < w[cnt]) {
						p = par[p][i];
					}
				}
				p = par[p][0];
				dep[cnt] = dep[p] + 1;
				par[cnt][0] = p;
				d[cnt] += d[p];
			}
			for(int i = 1; i < 20; ++i) par[cnt][i] = par[par[cnt][i-1]][i-1];
		} else {
			int p = a;
			for(int i = 19; i >= 0; --i) {
				if(par[p][i] != 0) if(d[a] - d[par[p][i]] <= b) {
					p = par[p][i];
				}
			}
			last = dep[a] - dep[p];
			if(d[a] <= b) last++;
			printf("%d\n", last);
		}
	}
}