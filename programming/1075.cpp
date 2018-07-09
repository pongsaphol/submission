#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

int main() {
	// freopen("r", "r", stdin);
	int T;
	scanf("%d", &T);
	vector<P> V; // x is C, y is D;
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		V.push_back({b, a});
	}
	sort(V.begin(), V.end());
	double r = 0.0;
	long long a1 = 0, a2 = 0;
	long long sum = 0;
	for(auto now: V) {
		sum += now.y;
		double tochk = (double)(sum)/((double)(now.x));
		if(tochk > r) {
			r = tochk;
			a1 = sum;
			a2 = now.x;
		}
	}
	printf("%lld %lld\n", a1, a2);
}