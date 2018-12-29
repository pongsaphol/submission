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


const int N = 2e5+5;

class TaskB {
private:
    long n;
    char S[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        cin >> S;
        long M = 998244353;
        long s1 = 1, s2 = 1;
        for(int i = 1; i < n; ++i) {
            if(S[i] == S[i-1]) s1++;
            else break;
        }
        for(int i = n-2; ~i; --i) {
            if(S[i] == S[i+1]) s2++;
            else break;
        }
        if(s1 == n) {
            cout <<  ((n * (n + 1) / 2) % M) << endl;
            return;
        }
        if(S[0] == S[n-1]) {
            cout << (((s1+1) * (s2+1)) % M) << endl;
            return;
        }
        cout <<  s1 + s2 + 1 << endl;
    }
};