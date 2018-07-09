#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

vector<P> SM[105], SR[105];
int n, m;
char A[4];

void solve() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		int z; scanf("%d", &z);
		SM[i].clear();
		while(z--) {
			scanf("%s", A);
			SM[i].emplace_back(A[1] - 'a', A[0] == '-');
		}
	}
	for(int i = 0; i < m; ++i) {
		int z; scanf("%d", &z);
		SR[i].clear();
		while(z--) {
			scanf("%s", A);
			SR[i].emplace_back(A[1] - 'a', A[0] == '-');
		}
	}
	for(int i = 0; i < (1 << 16); ++i) {
		bool lhs = true, rhs = true;
		for(int j = 0; j < n; ++j) {
			bool st = false;
			for(auto x : SM[j]) {
				bool now = (i & (1 << x.x));
				st |= (now ^ x.y);
			}
			lhs &= st;
		}
		for(int j = 0; j < m; ++j) {
			bool st = false;
			for(auto x : SR[j]) {
				bool now = (i & (1 << x.x));
				st |= (now ^ x.y);
			}
			rhs &= st;
		}
		if(lhs & !rhs) {
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--) solve();
}