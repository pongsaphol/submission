#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 1e5+5;

int n, k;
long d[N];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%lld", d+i), d[i] += d[i-1]; 
    map<int, int> M;
    M[0]++;
    long sum = 0;
    for(int i = 1; i <= n; ++i) {
        d[i] %= k;
        sum += M[d[i]];
        M[d[i]]++;
    }
    cout << sum << endl;
}