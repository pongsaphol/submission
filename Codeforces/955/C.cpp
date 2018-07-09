#include <bits/stdc++.h>
#define long long long
using namespace std;

double eps = 1e-9;

vector<int> A = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 30, 42};
vector<int> B = {6, 10, 14, 22, 26, 34, 38, 46, 58, 62, 15, 21, 33, 39, 51, 57, 35, 55};

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int T; scanf("%d", &T);
	// printf("%d %d\n", A.size(), B.size());
	while(T--) {
		long a, b; scanf("%lld %lld", &a, &b);
		bool st = false;
		if(a == 1) st = true, a++;
		long sum = 0;
		for(auto x : A) {
			long aa = (long)(pow(b, 1.0/x))-1;
			long bb = (long)(pow(a-eps, 1.0/x))-1;
			// cout << x << ":" << aa << " " << bb << endl;
			if(aa <= bb) continue;
			sum += aa - bb; 
		}
		for(auto x : B) {
			long aa = (long)(pow(b, 1.0/x))-1;
			long bb = (long)(pow(a-eps, 1.0/x))-1;
			if(aa <= bb) continue;
			sum -= aa - bb; 
		}
		cout << sum + st<< endl;
	}
}