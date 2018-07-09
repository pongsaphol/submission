#include <cstdio>

bool s[1005];

int main() {
	int idx = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; ++i) {
		if(s[i]) continue;
		for(int j = i; j <= n; j += i) {
			if(s[j]) continue;
			s[j] = true;
			if(++idx == m) {
				printf("%d\n" , j);
				return 0;
			}
		}
	}
}