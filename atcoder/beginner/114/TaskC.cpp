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


class TaskC {
private:
	int n;
	vector<int> vec;
	char inp[20];
	void check() {
	    int num; sscanf(inp, "%d", &num);
	    int bit = 0;
	    for(int i = 0; inp[i]; ++i) {
	        if(inp[i] == '3') bit |= 1;
	        if(inp[i] == '5') bit |= 2;
	        if(inp[i] == '7') bit |= 4;
	    }
	    if(bit == 7) vec.emplace_back(num);
    }
	void rec(int pos) {
	    inp[pos] = '\0';
	    if(pos) check();
	    if(pos == 9) return;
        inp[pos] = '3';
        rec(pos+1);
        inp[pos] = '5';
        rec(pos+1);
        inp[pos] = '7';
        rec(pos+1);
	}
public:
	void solve(istream& cin, ostream& cout) {
		cin >> n;
		rec(0);
		int sum = 0;
        for(int x : vec) if(x <= n) sum++;
        cout << sum << endl;
	}
};