#include <bits/stdc++.h>
#define input() (*istream_iterator<int>(cin))
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


class TaskA {
private:
    int n, m;
    vector<int> A, B;
    long ans;
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 0; i < n; ++i) A.emplace_back(input());
        for(int i = 0; i < m; ++i) B.emplace_back(input());
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end());
        if(*B.begin() < *A.begin()) {
            cout << -1 << endl;
            return;
        }
        if(B[0] == A[0]) {
            for(int v : B) ans += v;
            for(int i = 1; i < A.size(); ++i) ans += 1ll * A[i] * m;
        } else {
            for(int v : B) ans += v;
            ans += A[0];
            ans += 1ll * A[1] * (m-1);
            for(int i = 2; i < A.size(); ++i) ans += 1ll * A[i] * m;
        }
        cout << ans << endl;
    }
};