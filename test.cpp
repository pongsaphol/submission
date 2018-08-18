#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pii pair<int, int>
#define x first
#define y second

long f[105] = {0, 1, 2};

int main() {
    for(int i = 3; i <= 100; ++i) printf("%d -> %lld\n", i, f[i] += f[i-1] + f[i-2]); 
}