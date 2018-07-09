#include <cstdio>
#include <algorithm>
using std::swap;

int n, A[1005];



void read(int x) {
	if(x == n) return;
	scanf("%d", A+x);
	read(x + 1);
}

void re(int l, int r) {
	if(l > r) return;
	swap(A[l], A[r]);
	re(l+1, r-1);
}

void S(int x, int v) {
	if(A[x] < A[v]) {
		swap(A[x], A[v]);
		re(x+1, n-1);
		return;
	}else{
		S(x, v-1);
	}
}
void solve(int x) {
	if(A[x] < A[x+1]) {
		S(x, n-1);
		return;
	}	
	solve(x-1);
}

void print(int x) {
	if(x == n) return;
	printf("%d\n", A[x]);
	print(x+1);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &n);
	read(0);
	solve(n-2);
	print(0);
}