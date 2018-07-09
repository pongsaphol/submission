#include <cstdio>
#include <algorithm>
using namespace std;

char A[1005];
int p;

void sw(int l, int r) {
	if(l >= r) return;
	swap(A[l], A[r]);
	sw(l+1, r-1);
}

void rec(int x) {
	if(A[x] == '_') {
		sw(p, x-1);
		p = x+1;
	}
	if(A[x] == '\0') {
		sw(p, x-1);
		return;
	}
	rec(x+1);
}

void solve() {
	rec(0);
	printf("%s", A);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%s", A);
	solve();
}