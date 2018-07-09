#include <cstdio>
#include <algorithm>
using namespace std;

char A[1005];
int P[1005], idx = 1;

void rec(int x) {
	if(A[x] == '\0') return;
	if(A[x] == '_') P[idx++] = x+1;
	rec(x+1);
}

void print(int x) {
	if(A[x] == '_' || A[x] =='\0') return;
	printf("%c", A[x]);
	print(x+1);
}

void loop(int x) {
	if(x == 0) return;
	print(P[--x]);
	if(x != 0) printf("_");
	loop(x);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%s", A);
	// P[idx++] = 0;
	rec(0);
	loop(idx);
}