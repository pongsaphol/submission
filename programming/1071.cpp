#include <bits/stdc++.h>
using namespace std;

int n, m;
bool d[1005][1005];

int f(int x) {
	if(x < 0) x = 0;
	if(x > 1000) x = 1000;
	return x;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	while(n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		d[a][b] = true;
	}
	while(m--) {
		int sum = 0;
		int x, y, r;
		scanf("%d %d %d", &x, &y, &r);
		for(int i = f(x-r); i <= f(x+r); ++i)
			for(int j = f(y-r); j <= f(y+r); ++j) 
				if(d[i][j]) {
					sum++;
					d[i][j] = false;
				}
	
		printf("%d\n", sum);
	}
}