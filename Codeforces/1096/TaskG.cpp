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

const int N = 1<<20;
const long M = 998244353, G = 3;

class DFT_prog {
private:
int n, k;
    long A[N];
    long power(long a, long r) {
        long ret = 1;
        for(; r; r >>= 1, a = a * a % M) if(r & 1) ret = ret * a % M;
        return ret;
    }
    void DFT(long A[], int n, bool inv = false) {
        int *rev = new int[n];
        for(int i = 0; i < n; ++i) {
            rev[i] = i ? rev[i>>1] >> 1 | (i & 1 ? n >> 1 : 0) : 0;
            if(i < rev[i]) swap(A[i], A[rev[i]]);
        }
        delete []rev;
        for(int m = 1; m < n; m <<= 1) {
            long omega = power(G, (M-1) / m >> 1);
            if(inv) omega = power(omega, M-2);
            for(int j = 0; j < n; j += m << 1) {
                long *l = A+j, *r = l+m, w = 1, u, v;
                for(int k = 0; k < m; ++k, ++l, ++r, w = w * omega % M) {
                    u = *l, v = *r * w % M;
                    *l = (u + v) % M;
                    *r = (u - v + M) % M;
                }
            }
        }
        if(inv) {
            long z = power(n, M-2);
            for(int i = 0; i < n; ++i, ++A) *A = *A * z % M;
        }
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k;
        for(int i = 0, val; i < k; ++i) cin >> val, A[val] = 1;
        int m = 1<<20;
        DFT(A, m);
        for(int i = 0; i < m; ++i) A[i] = power(A[i], n / 2);
        DFT(A, m, true);
        long ans = 0;
        for(int i = 0; i < m; ++i) ans = (ans + A[i] * A[i]) % M;
        cout << ans << endl;
    }
};
