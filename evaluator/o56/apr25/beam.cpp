#include <bits/stdc++.h>
using namespace std;

struct data {
	int x, y, v;
};
/*
->	1;
^
|	2;
|
v	3;
<-	4;
*/
int r, c, m, n;
set<int> R[MAXN], C[MAXN], RR[MAXN], CC[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d %d", &r, &c, &m, &n);
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		R[a].emplace(b);
		C[b].emplace(a);
	}
	while(n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		RR[a].emplace(b);
		CC[b].emplace(a);
	}
	data now(1, 0, 1);
}