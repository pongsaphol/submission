#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;

const int N = 1250+5, INF = 1e9;

int n, m, tr[N][N<<1], tc[N][N<<1], A[N][N], dp[N][N], qsr[N][N], qsc[N][N];
vector<vector<int> > R(N), C(N);

void updt(int t[], int x, int v) {
	x += N;
	for(t[x] = min(t[x], v); x != 1; x >>= 1) t[x>>1] = min(t[x], t[x^1]);
}

int quet(int t[], int l, int r) {
	int mn = INF;
	for(l += N, r += N+1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) mn = min(mn, t[l++]);
		if(r & 1) mn = min(mn, t[--r]);
	}
	return mn;
}

int main() {
	fill(tr[0], tr[N-1] + 2*N, INF);
	fill(tc[0], tc[N-1] + 2*N, INF);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) scanf("%d", A[i]+j),
		R[i].emplace_back(A[i][j]), C[j].emplace_back(A[i][j]),
		qsr[i][j] = qsr[i][j-1] + A[i][j], qsc[i][j] = qsc[i-1][j] + A[i][j];
	for(int i = 1; i <= n; ++i) sort(all(R[i])), R[i].resize(unique(all(R[i])) - R[i].begin());
	for(int j = 1; j <= m; ++j) sort(all(C[j])), C[j].resize(unique(all(C[j])) - C[j].begin());
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		int ir = lower_bound(all(R[i]), A[i][j]) - R[i].begin(), jc = lower_bound(all(C[j]), A[i][j]) - C[j].begin();
		assert(R[i][ir] == A[i][j]), assert(C[j][jc] == A[i][j]);
		if(i == 1 && j == 1) dp[i][j] = 0;
		else dp[i][j] = min(qsr[i][j-1] + quet(tr[i], 0, ir-1), qsc[i-1][j] + quet(tc[j], 0, jc-1));
		updt(tr[i], ir, dp[i][j] - qsr[i][j]), updt(tc[j], jc, dp[i][j] - qsc[i][j]);
	}
	printf("%d\n", dp[n][m] >= INF ? -1 : dp[n][m]);
}