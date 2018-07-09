#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
	
// I will use hash 129, 131
	
const int N = 1e6+5;
	
int n, m;
char A[N], B[N], ans[N];
pii Z[N];
	
pii iden(129, 131);
pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
pii mul(pii a, pii b) { return pii(a.x * b.x, a.y * b.y); }
pii sub(pii a, pii b) { return pii(a.x - b.x, a.y - b.y); }
	
void solve() {
	scanf("%s %s", A, B);
	n = strlen(A), m = strlen(B);
	pii ret(0, 0), pw(1, 1);
	for(int i = 0; i < m; ++i) {
		ret = add(mul(ret, iden), pii(B[i], B[i]));
		pw = mul(pw, iden);
	}
	int ptr = 1;
	for(int i = 0; i < n; ++i, ++ptr) {
		Z[ptr] = add(mul(Z[ptr-1], iden), pii(A[i], A[i]));
		ans[ptr] = A[i];
		if(ptr >= m) if(sub(Z[ptr], mul(pw, Z[ptr-m])) == ret) ptr -= m;
	}
	ans[ptr] = 0;
	if(ptr == 1) puts("No COI Secret Code");
	else printf("%s\n", ans+1);
}	
	
int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
}	