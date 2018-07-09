#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define P pair<int,int>
#define x first
#define y second
#define long long long
using namespace std;

vector<P> V;
int n;

bool cmpf(const P &a, const P &b) {
	return 2*a.x-a.y < 2*b.x-b.y; 
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &n);
	long sum = 0;
	for(int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(2*a <= b) sum += b - 2*a;
		else V.push_back({a, b});
	}
	sort(V.begin(), V.end(), cmpf);
	int size = V.size();
	long toerase = (long)size*size;
	long cache = 0;
	for(auto now:V) {
		size--;
		cache -= now.y-2*now.x;
		toerase = min(toerase, cache + (long)size*size);
	}
	printf("%lld", sum - toerase);
}