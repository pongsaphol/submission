#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char A[4][8] = {"ABC", "BABC", "CCAABB"};
int n, score[4], z[] = {3, 4, 6};
char arr[105], p[4][15] = {"Adrian", "Bruno", "Goran" };

int main() {
	scanf("%d", &n);
	scanf("%s", arr);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(arr[i] == A[j][i%z[j]]) score[j]++;
		}
	}
	int mx = 0;
	for(int i = 0; i < 3; ++i) mx = max(mx, score[i]);
	printf("%d\n", mx);
	for(int i = 0; i < 3; ++i) if(score[i] == mx) {
		printf("%s\n", p[i]);
	}
}