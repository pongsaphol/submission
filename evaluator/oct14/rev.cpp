#include <cstdio>
#include <cstring>

char A[1005];

void loop(int x) {
	printf("%c", A[x]);
	if(x == 0) return;
	loop(x-1);
}

int main() {
	scanf("%s", A);
	int len = strlen(A);
	loop(len-1);
}