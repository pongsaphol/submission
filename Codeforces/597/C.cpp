#include <bits/stdc++.h>
#define long unsigned long long
using namespace std;

const int MAXN = 1e5 + 5;

int n, k;
long t[12][MAXN];

void update(long t[], int x, long v) {
	for(int i = x; i <= n; i += i&-i) t[i] += v;
}

long query(long t[], int x) {
	long sum = 0;
	for(int i = x; i != 0; i -= i&-i) sum += t[i];
	return sum;
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &k);
	k++;
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		for(int j = k; j != 1; --j) update(t[j], now, query(t[j-1], now));
		update(t[1], now, 1);
	}
	printf("%llu\n", query(t[k], n));
}