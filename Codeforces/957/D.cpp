#include <bits/stdc++.h>
using namespace std;

int mo, le;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int n; scanf("%d", &n);
	long long sum = 0;
	int cntsen = 1;
	for(int i = 1; i <= n; ++i) {
		int ret; scanf("%d", &ret);
		if(ret >= cntsen) {
			// cout << "do" << endl;
			cntsen++;
			if(ret >= cntsen) {
				// cout << "fuck" << endl;
				long long dip = ret - cntsen + 1;
				sum += ((dip)*(dip+1)) / 2;
				cntsen = ret + 1;
			}
		} else {
			sum += max(0, cntsen - ret - 1);
		}
		// cout << sum << endl;
	}
	cout << sum;
}