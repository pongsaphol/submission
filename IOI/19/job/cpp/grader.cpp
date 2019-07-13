#include "job.h"
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int main() {
	int n;
	assert(1 == scanf("%d", &n));
	std::vector<int> p(n);
	for (int i = 0; i < n; i++) {
		assert(1 == scanf("%d", &p[i]));
	}
	std::vector<int> u(n);
	for (int i = 0; i < n; i++) {
		assert(1 == scanf("%d", &u[i]));
	}
	std::vector<int> d(n);
	for (int i = 0; i < n; i++) {
		assert(1 == scanf("%d", &d[i]));
	}
	long long result = scheduling_cost(p, u, d);
	printf("%lld\n", result);
	return 0;
}
