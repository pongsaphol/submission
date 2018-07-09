#include <bits/stdc++.h>
using namespace std;

void ref() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

const int MAXN = 1e5+5;

int n, A[MAXN];
bool chk[MAXN];

void solve() {
	scanf("%d", &n);
	set<int> S, wu;
	for(int i = 1; i <= n; ++i) S.emplace(i), wu.emplace(i);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		if(A[i] == 0) {
			S.emplace(i);
			wu.emplace(i);
		}
	}
	for(int i = 1; i <= n; ++i) if(S.find(A[i]) != S.end()) S.erase(A[i]);
	printf("S ->");
	for(auto x:S) printf("%d ", x);
	printf("\nW ->");
	for(auto x:wu) printf("%d ", x);
	printf("\n");
	int pv = *S.begin();
	S.erase(*S.begin());
	while(!S.empty()) {
		A[pv] = *S.begin();
		pv = *S.begin();
		wu.erase(*S.begin());
		S.erase(*S.begin());
	}
	printf("->%d\n", wu.size());
	for(int i = 1; i <= n; ++i) {
		if(A[i] == 0) {
			A[i] = *wu.begin();
			wu.erase(wu.begin());
		}
	}
	int cnt = 0;
	// for(int i = 1; i <= n; ++i) {
	// 	if(!chk[i]) {
	// 		int now = i;
	// 		chk[i] = true;
	// 		while(A[now] != i) {
	// 			chk[now] = true;
	// 			now = A[i];
	// 		}
	// 		cnt++;
	// 	}
	// }
	for(int i = 1; i <= n; ++i) chk[i] = false;
	printf("%d\n", n-cnt);
	for(int i = 1; i <= n; ++i) printf("%d ", A[i]);
	printf("\n");
}

int main() {
	ref();
	int T;
	scanf("%d", &T);
	while(T--) solve();
}