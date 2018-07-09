#include <cstdio>

int main() {
	// freopen("r", "r", stdin);
	int n = 2;
	int x = (n+1)/2;
	for(int i = 1; i <= x; ++i) {
		for(int j = x; j > i; --j) printf("-");
		printf("*");
		for(int j = 1; j <= 2*i-3; ++j) printf("-");
		if(i != 1)printf("*");
		for(int j = x; j > i; --j) printf("-");
		printf("\n");
	}
	int z = x;
	if(n%2) z--;
	for(int i = z; i >= 1; --i) {
		for(int j = x; j > i; --j) printf("-");
		printf("*");
		for(int j = 1; j <= 2*i-3; ++j) printf("-");
		if(i != 1) printf("*");
		for(int j = x; j > i; --j) printf("-");
		printf("\n");
	}
}