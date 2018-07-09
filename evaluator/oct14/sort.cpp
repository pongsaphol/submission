#include <cstdio>
#include <algorithm>
using namespace std;

int n, A[1005];

void read(int x) {
	if(x == n) return;
	scanf("%d", A+x);
	read(x+1);
}

void S(int x) {
	if(x == n) return;
	if(A[x] < A[x-1]) swap(A[x], A[x-1]);
	S(x+1);
}

void sort(int x) {
	if(x == 0) return;
	S(1);
	sort(x-1);
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
	sort(n);
	print(0);
}