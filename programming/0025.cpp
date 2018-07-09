#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[105];

int main() {
	// freopen("r", "r", stdin);
	scanf("%s", a);
	int i = strlen(a);
	char op;
	scanf(" %c", &op);
	scanf("%s", a);
	int j = strlen(a);
	if(op == '+') {
		if(i == j) {
			printf("2");
			while(--i) printf("0");
		}else{
			if(i < j) swap(i, j);
			printf("1");
			while(--i) if(i != j) printf("0");
				else printf("1");
		}
	}else {
		printf("1");
		i+=j-1;
		while(--i) printf("0");
	}
}