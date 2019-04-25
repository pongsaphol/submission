#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 1e5+5;

class TaskB {
private:
    int n;
    char str[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        cin >> str;
        int cnt = 0;
        for(int i = 0; i < n-10; ++i) if(str[i] == '8') ++cnt;
        int z = n-9;
        z >>= 1;
        cout << (cnt >= z ? "YES" : "NO") << endl;
    }
};