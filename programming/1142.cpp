#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

const int MAXN = 1<<17;

int n, m, t[MAXN<<1], lz[MAXN<<1];
P arr[MAXN];

void update(int l, int r, int ptr = 1,int st = 1, int ed = MAXN) {
	if(lz[ptr] != 0) {
		t[ptr] += lz[ptr];
		if(st != ed) {
			lz[ptr<<1] += lz[ptr];
			lz[ptr<<1|1] += lz[ptr];
		}
		lz[ptr] = 0;
	}
	if(l > ed || st > r) return;
	if(l <= st && ed <= r) {
		t[ptr]++;
		if(st != ed) {
			lz[ptr<<1]++;
			lz[ptr<<1|1]++;
		}
		return;
	}
	int mid = (st+ed)/2;
	update(l, r, ptr<<1, st, mid);
	update(l, r, ptr<<1|1, mid+1, ed);
	t[ptr] = max(t[ptr<<1], t[ptr<<1|1]);
}	

int query(int l, int r, int ptr = 1, int st = 1, int ed = MAXN) {
	if(lz[ptr] != 0) {
		t[ptr] += lz[ptr];
		if(st != ed) {
			lz[ptr<<1] += lz[ptr];
			lz[ptr<<1|1] += lz[ptr];
		}
		lz[ptr] = 0;
	}
	if(l > ed || st > r) return 0;
	if(l <= st && ed <= r) return t[ptr];
	int mid = (st+ed)/2;
	return max(query(l, r, ptr<<1, st, mid), query(l, r, ptr<<1|1, mid+1, ed)); 
}	


int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	map<int, int> M;
	for(int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i] = {a, b};
		M[a] = 1, M[b] = 1;
	}
	int idx = 0;
	for(auto &i:M) i.y = ++idx;
	for(int i = 1; i <= n; ++i) {
		P z = arr[i];
		z = {M[z.x], M[z.y]};
		// printf("%d %d\n", z.x, z.y);
		if(query(z.x, z.y) < m) {
			printf("yes\n");
			update(z.x, z.y);
		} else {
			printf("no\n");
		}
		// for(int i = 1; i < 16; ++i) printf("%d:: %d %d\n", i, t[i], lz[i]);
		// printf("------\n");
	}
	return 0;
}
/* 1 3 4 5 6 7 8 10
   1 2 3 4 5 6 7 8
*/