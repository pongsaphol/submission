#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;

int n, X[N], Y[N];
map<int, int> x, y;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", X+i, Y+i);
        x[X[i]]++, y[Y[i]]++;
    }
    long long sum = 0;
    for(int i = 0; i < n; ++i) 
        sum += 1ll * (x[X[i]] - 1) * (y[Y[i]] - 1);
    printf("%lld\n", sum);
}
