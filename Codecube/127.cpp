#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	if(m == 1) {
		if(n == 2) printf("2-1\n");
		if(n == 3) printf("3-2*1\n");
		if(n == 4) printf("2+3-4*1\n");
		if(n >= 5) {
			printf("5-4+2-3");
			for(int i = 6; i <= n; ++i) printf("*%d", i);
			printf("+1\n");
		}
	}
	if(m == 2) {
		if(n == 2) printf("2*1\n");
		if(n == 3) printf("3-2+1\n");
		if(n >= 4) {
			printf("4-3-1");
			for(int i = 5; i <= n; ++i) printf("*%d", i);
			printf("+2\n");
		}
	}
	if(m == 3) {
		if(n == 3) printf("2-1*3\n");
		if(n == 4) printf("4-2-1*3\n");
		if(n >= 5) {
			printf("5+1-4-2");
			for(int i = 6; i <= n; ++i) printf("*%d", i);
			printf("+3\n");
		}
	}
	if(m >= 4) {
		printf("3-2-1");
		for(int i = 4; i <= n; ++i) if(i != m) printf("*%d", i);
		printf("+%d\n", m);
	}
}