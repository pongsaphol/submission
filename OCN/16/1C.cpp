#include <bits/stdc++.h>
#define long long long 
using namespace std;

const long M = 1e9+7;
const int N = 1e6+5;

string str;
long n, m, k;

long powz(long a, long b) {
    long ret = 1;
    for(; b; b >>= 1) {
        if(b & 1) ret = ret * a % M;
        a = a * a % M;
    }
    return ret;
}

long frac[N], ifrac[N];

int main() {
    frac[0] = ifrac[0] = 1;
    for(int i = 1; i < N; ++i) ifrac[i] = powz(frac[i] = frac[i-1] * i % M, M-2);
    for(int i = 0; i < N; ++i) assert(frac[i] * ifrac[i] % M == 1);
    cin >> str;
    cin >> n >> m >> k;
    cin >> str;    
    long z = m * (n-1);
    long val = powz(2, z);
    val = val * frac[m] % M; 
    val = val * ifrac[m-k] % M; 
    val = val * ifrac[k] % M; 
    printf("%lld\n", val);
}
