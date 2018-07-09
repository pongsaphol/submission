#include <bits/stdc++.h>
#define long long long
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
using namespace std;


const int MAXN = 1e5 + 5;

int n, m, que[MAXN][2], l[MAXN], r[MAXN], ans[MAXN];
long t1[MAXN], t2[MAXN];
double dque[MAXN];
vector<P> V;
vector<int> todo[MAXN];

void upd(long t[], int x, int v) { for(int i = x; i <= n; i += i&-i) t[i] += v; }
long get(long t[], int x) { long sum = 0; for(int i = x; i != 0; i -= i&-i) sum += t[i]; return sum; }

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int now; scanf("%d", &now);
		V.emplace_back(now, i);
	}
	sort(all(V), greater<P>());
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d %lf", que[i], que[i]+1, dque + i);
		l[i] = 0, r[i] = n-1;
	}
	bool done = true;
	int cnt = 5;
	while(done) {
		done = false;
		memset(t1, 0, sizeof t1), memset(t2, 0, sizeof t2);
		for(int i = 1; i <= m; ++i) if(l[i] < r[i]) todo[(l[i] + r[i] + 1) >> 1].emplace_back(i);
		for(int i = 0; i < n; ++i) {
			upd(t1, V[i].y, V[i].x), upd(t2, V[i].y, 1);
			// printf("=== %d ===\n", i);
			while(!todo[i].empty()) {
				int x = todo[i].back(); todo[i].pop_back();
				// printf("->%d %d\n", x, i);
				done = true;
				long sead = get(t1, que[x][1]) - get(t1, que[x][0]-1);
				long suan = get(t2, que[x][1]) - get(t2, que[x][0]-1);
				double now = (double)sead / suan;
				if(suan == 0) {
					r[x] = i-1;
					continue;
				}
				if(now >= dque[x]) {
					l[x] = i;
					ans[x] = suan;
				} else r[x] = i-1;
 			}
		}
	}
	for(int i = 1; i <= m; ++i) {
		int sz = que[i][1] - que[i][0] + 1;
		// printf("%d\n", ans[i]);
		if(ans[i]) printf("%d\n", sz - ans[i]);
		else puts("-1");
	}
}