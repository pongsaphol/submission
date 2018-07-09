#include <cstdio>
#include <utility>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

P A[50];

int main() {
	A[1] = {0, 1};
	for(int i = 2; i <= 45; ++i) {
		A[i] = {A[i-1].y,A[i-1].y + A[i-1].x};
	}
	int n;
	scanf("%d", &n);
	printf("%d %d\n", A[n].x, A[n].y);
	return 0;
}