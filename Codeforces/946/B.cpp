#include <bits/stdc++.h>
#define long long long
using namespace std;


int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif	
	long a, b;
	cin >> a >> b;
	while(1) {
		if(a == 0 || b == 0) break;
		if(a >= 2 *b) {
			long dip = (a / (2*b));
			a -= dip * (2*b);
		} else if(b >= 2 * a) {
			long dip = (b / (2*a));
			b -= dip * (2*a);
		} else break;
	}
	cout << a << ' ' << b << endl;
}