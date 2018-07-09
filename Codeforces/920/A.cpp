#include <bits/stdc++.h>
using namespace std;

void ref() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

void solve() {
	int n, m;
	bool chk[2][205];
	memset(chk, 0, sizeof chk);
	scanf("%d %d", &n, &m);
	while(m--) {
		int now;
		scanf("%d", &now);
		chk[1][now] = true;
	}
	bool st = true;
	for(int i = 1; i <= n; ++i) st &= chk[1][i];
	if(st) {
		puts("1");
		return;
	}
	for(int i = 2; i <= 200; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(chk[(i-1)&1][j]) {
				chk[i&1][j-1] = chk[i&1][j] = chk[i&1][j+1] = true;
			}
		}
		bool st = true;
		for(int j = 1; j <= n; ++j) {
			st &= chk[i&1][j];
		}
		if(st) {
			printf("%d\n", i);
			return;
		}
	}
}

int main() {
	ref();
	int T;
	scanf("%d", &T);
	while(T--) solve();
}