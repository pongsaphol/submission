#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

char A[20];
char ret[20];
int n, c[4], x[4] = {0, 5, 0, 5} , y[4] = {0, 2, 5, 7}, ans = inf;

void init() {
	for(int i = 1; i <= n; ++i) ret[i] = A[i] - '0';
}

void solve(int idx) {
	init();
	int total = 0;
	if(ret[n] != x[idx]) {
		bool st = true;
		int cc = 1;
		for(int i = n-1; i; --i, ++cc) {
			if(ret[i] == x[idx]) {
				for(int j = i; j < n; ++j) ret[j] = ret[j+1];
				st = false;
				break;
			}
		}
		if(st) return;
		total += cc;
	}
	if(ret[n-1] != y[idx]) {
		bool st = true;
		int cc = 1;
		for(int i = n - 2; i; --i, ++cc) {
			if(ret[i] == y[idx]) {
				for(int j = i; j < n-1; ++j) ret[j] = ret[j+1];
				st = false;
				break;
			}
		}
		if(st) return;
		total += cc;
	}
	if(ret[1] == 0) {
		int cc = 1;
		bool st = true;
		for(int i = 2; i < n-1; ++i, ++cc) {
			if(ret[i] != 0) {
				st = false;
				break;
			}
		}
		if(st) return;
		total += cc;
	}
	ans = min(ans, total);
}

int main() {
	scanf("%s", A+1);
	n = strlen(A+1);
	for(int i = 0; i < 4; ++i) solve(i);
	if(ans == inf) puts("-1");
	else printf("%d\n", ans);
}