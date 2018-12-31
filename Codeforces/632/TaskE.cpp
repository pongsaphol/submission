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
const long M = 998244353;

class TaskE {
private:
    int n, k;
    long A[N];
    long power(long a, long r) {
        long ret = 1;
        for(; r; r >>= 1, a = a * a % M) if(r & 1) ret = ret * a % M;
        return ret;
    }
    void NTT(long A[], bool inv = false) {
        int *rev = new int[N];
        for(int i = 0; i < N; ++i) if(i < (rev[i] = rev[i>>1]>>1 | ((i&1) * (N>>1)))) swap(A[i], A[rev[i]]);
        for(int i = 1; i < N; i <<= 1) {
            long omega = power(3, (M-1) / i >> 1);
            if(inv) omega = power(omega, M-2);
            for(int j = 0; j < N; j += i << 1) {
                long w = 1, u, v;
                int l = j, r = i+j;
                for(int k = 0; k < i; k++, l++, r++, w = w * omega % M) {
                    u = A[l], v = A[r] * w % M;
                    A[l] = (u + v) % M;
                    A[r] = (u - v + M) % M;
                }
            }
        }
        if(inv) {
            long z = power(N, M-2);
            for(int i = 0; i < N; ++i) A[i] = A[i] * z % M;
        }
    }
public:
    void solve(istream& cin, ostream& cout) {
        srand(time(NULL));
        cin >> n >> k;
        for(int i = 0, val; i < n; ++i) cin >> val, A[val] = rand() % M;
        NTT(A);
        for(int i = 0; i < N; ++i) A[i] = power(A[i], k);
        NTT(A, true);
        for(int i = 0; i < N; ++i) if(A[i]) cout << i << ' ';
        cout << endl;
    }
};