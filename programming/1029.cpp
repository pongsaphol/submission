#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 2e5;

int n, m, k, sz = 0, barr[MAXN + 25];
set<int> S;
set<int>::iterator it;

void in(int idx) {
	it = S.find(idx);
	if(it == S.end()) S.insert(idx);
	else S.erase(it);
}

void build() {
	for(auto x:S) barr[++sz] = x;
}

int low(int x) {
	// it is <=
	int L = 1, R = sz, mid;
	while(L < R) {
		mid = (L + R + 1)/2;
		if(barr[mid] <= x) L = mid;
		else R = mid - 1;
	}
	return barr[L];
}

int up(int x) {
	// it is >
	int L = 1, R = sz, mid;
	while(L < R) {
		mid = (L + R)/2;
		if(barr[mid] > x) R = mid; 
		else L = mid + 1;
	}
	return barr[R];
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		in(a);
		in(a+b);
	}
	S.insert(1);
	S.insert(n+1);
	build();
	while(k--) {
		int x;
		scanf("%d", &x);
		int a = low(x);
		int b = up(x);
		printf("%d\n", b - a);
	}
}