#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	for(int i = 1, a; i <= n; ++i) {
		scanf("%d", &a);
		if(~a & 1) a--;
		printf("%d ", a);
	}
}
