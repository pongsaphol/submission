#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 1e6+5;

long M = 998244353;
long A[N], dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    long a = 0, b = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> A[i];
        a <<= 1;
        a %= M;
        a += A[i];
        a %= M;
        dp[i] = b + a;
        dp[i] %= M;
        b += dp[i];
        b %= M;
    }
    cout << dp[n];
}