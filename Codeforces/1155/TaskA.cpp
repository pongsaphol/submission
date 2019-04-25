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

const int N = 3e5+5;

class TaskA {
private:
    int n;
    char A[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        cin >> A;
        for(int i = 1; i < n; ++i) {
            if(A[i] < A[i-1]) {
                cout << "YES" << endl;
                cout << i << ' ' << i+1 << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
};