#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

set<double> S;
bool k;
int main() {
	red();
	int n;
	double x, y;
	cin >> n >> x >> y;
	while(n--) {
		double a, b;
		cin >> a >> b;
		if(y == b) k = true;
		else S.emplace((x-a)/(y-b));
	}
	cout << S.size()+k;
}