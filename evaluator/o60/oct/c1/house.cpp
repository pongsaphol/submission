#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

const int MAXN = 1<<18;

int n, m, A[MAXN], tl[MAXN<<1], tr[MAXN<<1], tx[MAXN<<1];

struct node {
	int a, b, c;
};

void build(int ptr = 1, int L = 1, int R = n) {
	if(L == R) {
		tl[ptr] = tr[ptr] = tx[ptr] = A[L] - A[R-1];
		return;
	}
	int mid = (L+R)/2;
	build(ptr<<1, L, mid);
	build(ptr<<1|1, mid+1, R);
	tl[ptr] = max(tl[ptr<<1], A[mid] - A[L-1] + tl[ptr<<1|1]);
	tr[ptr] = max(tr[ptr<<1|1], A[R] - A[mid] + tr[ptr<<1]);
	tx[ptr] = max(max(tx[ptr<<1], tx[ptr<<1|1]), tl[ptr<<1|1] + tr[ptr<<1]);
}

node query(int x, int y, int ptr = 1, int L = 1, int R = n) {
	if(x == L && y == R) return {tl[ptr], tr[ptr], tx[ptr]};
	int mid = (L+R)/2;
	if(y <= mid) return query(x, y, ptr<<1, L, mid);
	if(x > mid) return query(x, y, ptr<<1|1, mid+1, R);
	node a = query(x, mid, ptr<<1, L, mid);
	node b = query(mid+1, y, ptr<<1|1, mid+1, R);
	node cur;
	cur.a = max(a.a, A[mid] - A[x-1] + b.a);
	cur.b = max(b.b, A[y] - A[mid] + a.b);
	cur.c = max(max(a.c, b.c), a.b + b.a);
	return cur;
}

int main() {
	red();
 	scanf("%d%d", &n, &m);
 	for(int i = 1; i <= n; ++i) {
 		scanf("%d", A+i);
 		A[i] += A[i-1];
 	}
 	build();
 	while(m--) {
 		int a, b;
 		scanf("%d%d", &a, &b);
 		int now = query(++a, ++b).c;
 		if(now > 0) printf("%d\n", now);
 		else puts("0");
 	}
}