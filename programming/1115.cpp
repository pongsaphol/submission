#include <cstdio>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

typedef struct E {
	int u, v, w;
	friend inline bool operator<(const E &a, const E &b) {
		return a.w < b.w;
	}
} E;

int f(int a) { return a*a; }

int n, m, P[1005];
pii arr[1005];

int find(int u) {
	if(P[u] == u) return u;
	return P[u] = find(P[u]);
}

int main() {
	// freopen("r", "r", stdin);
	vector<E> V;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		P[i] = i;
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i] = {a, b};
		for(int j = i-1; j >= 1; --j) {
			V.push_back({i, j, f(a-arr[j].x) + f(b-arr[j].y)});
		}
	}
	int ans = -1;
	sort(V.begin(), V.end());
	int idx = 0;
	for(auto i:V) {
		int u = find(i.u);
		int v = find(i.v);
		if(u != v) {
			P[u] = v;
			if(++idx == n-m) {
				ans = i.w;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}