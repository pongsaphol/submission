#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int h, m;
	scanf("%d %d", &h, &m);
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int cnt = (a / d) + (a%d ? 1 : 0);
	double mn = cnt * c;
	while(h < 20) {
		m++;
		a += b;
		if(m == 60) {
			m = 0;
			h++;
		}
		if(h == 24) {
			h = 0;
		}
	}
	cnt = (a / d) + (a%d ? 1 : 0);
	mn = min(mn, cnt * (double)c * 4 / 5);
	printf("%.4f", mn);
}