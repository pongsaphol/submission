#include <cstdio>
#include <vector>
#include <algorithm>
#define x first
#define y second
using namespace std;

vector<pair<double, int> > V;

int main() {
	// freopen("r", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		V.push_back({(double)a/(double)b, b});
	}
	sort(V.begin(), V.end());
	int idx = 0;
	scanf("%d", &T);
	while(T--) {
		int now;
		scanf("%d", &now);
		double ans = 0.0;
		do {
			if(V[idx].y - now > 0) {
				ans += V[idx].x * now;
				V[idx].y -= now;
				now = 0;
			}else{
				ans += V[idx].x * V[idx].y;
				now -= V[idx].y;
				idx++;
			}
		}while(now > 0);
		printf("%.3f\n", ans);
	}
	return 0;
}