#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};


class TaskB {
private:
	string str;
	char A[5];
public:
	void solve(istream& cin, ostream& cout) {
		cin >> str;
		int mn = 1e5;
		for(int i = 0; i < (int)str.size() - 2; ++i) {
			for(int j = 0; j < 3; ++j) A[j] = str[i+j];
			int val;
			sscanf(A, "%d", &val);
			mn = min(mn, abs(val - 753));
		}
		cout << mn << endl;
	}
};