#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c, d;

int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	double mx = 0.0;
	int ans;
	for(int i = 0; i < 4; ++i) {
		double now = double(a)/double(c) + double(b)/double(d);
		if(now > mx) {
			mx = now;
			ans = i;
		}
		int cache;
		swap(cache, a);
		swap(cache, b);
		swap(cache, d);
		swap(cache, c);
		swap(cache, a);
	}
	printf("%d\n", ans);
}