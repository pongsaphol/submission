#include <cstdio>

const int MOD = 1e9-1, MAXN = 8e4;

int n, m, t[45][MAXN+5];

void update(int T, int idx, int val) {
	while(idx >= 1) {
		t[T][idx] += val;
		t[T][idx] %= MOD;
		idx -= idx&(-idx);
	}
}

int query(int T, int idx) {
	int val = 0;
	while(idx <= MAXN) {
		val += t[T][idx];
		val %= MOD;
		idx += idx&(-idx);
	}
	return val;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		update(1, x, 1);
		for(int j = 2; j <= m; ++j) {
			update(j, x, query(j-1, x+1));
		}
	}
	printf("%d\n", query(m, 1));
}