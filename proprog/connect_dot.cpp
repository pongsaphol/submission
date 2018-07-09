#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define x first
#define y second
#define p2(a) (a)*(a)
using namespace std;

typedef struct E {
	int u, v;
	float d;	
	friend inline bool operator<(const E &a, const E &b) {
		return a.d < b.d;
	}
}E;

pair<float, float> arr[105];
int P[105];

float dis(int a, int b) {
	return sqrt(p2(arr[a].x - arr[b].x) + p2(arr[a].y - arr[b].y));
}

int find(int u) {
	if(P[u] == u) return u;
	return P[u] = find(P[u]);
}

void solve() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		P[i] = i;
		float a, b;
		scanf("%f %f", &a, &b);
		arr[i] = {a, b};
	}
	vector<E> V;
	for(int i = 1; i <= n; ++i) {
		for(int j = i+1; j <= n; ++j) {
			V.push_back({i, j, dis(i, j)});
		}
	}
	sort(V.begin(), V.end());
	float ans = 0.0;
	for(auto x:V) {
		int u = find(x.u);
		int v = find(x.v);
		if(u != v) {
			P[u] = v;
			ans += x.d;
		}
	}
	printf("%.2f\n", ans);
}

int main() {
	freopen("r", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		solve();
		if(T) printf("\n");
	}
}