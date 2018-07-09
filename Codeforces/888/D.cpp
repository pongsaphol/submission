#include <bits/stdc++.h>
#define long long long
using namespace std;

int n, k;

long c(long a, long b) {
    long ret = 1;
    for(long z = a - b + 1; z <= a; ++z) ret *= z;
    for(; b; b--) ret /= b;
    return ret;
}

long d(long r) {
    vector<int> V;
    for(int i = 0; i < r; ++i) V.emplace_back(i);    
    long cnt = 0;
    while(next_permutation(V.begin(), V.end())) {
        bool st = true;
        for(int i = 0; i < r; ++i) if(V[i] == i) st = false;
        cnt += st;
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &k);
    long sum = 1;
    for(int i = 0; i <= k; ++i) sum += c(n, i) * d(i);
    cout << sum << endl;
}