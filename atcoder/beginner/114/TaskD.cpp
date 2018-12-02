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


class TaskD {
private:
    int n, c3, c5, c15, c25, c75;
    vector<int> prime;
public:
	void solve(istream& cin, ostream& cout) {
	    cin >> n;
        for(int i = 2; i <= 100; ++i) {
            bool st = true;
            for(int j = 2; j < i; ++j) if(i % j == 0) st = false;
            if(st) prime.emplace_back(i);
        }
        for(auto x : prime) {
            int cnt = 0;
            for(int i = 2; i <= n; ++i) {
                int z = i;
                while(z % x == 0) z /= x, cnt++;
            }
            if(cnt >= 2) c3++;
            if(cnt >= 4) c5++;
            if(cnt >= 14) c15++;
            if(cnt >= 24) c25++;
            if(cnt >= 74) c75++;
        }
        int ans = 0;
        ans += c5 * (c5 - 1) / 2 * (c3 - 2);
        ans += c15 * (c5 - 1);
        ans += c25 * (c3 - 1);
        ans += c75;
        cout << ans << endl;
	}
};