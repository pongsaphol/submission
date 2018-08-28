#include <bits/stdc++.h>
using namespace std;

#define long long long 

const int N = 1<<18;

int n, q, s, t;
long T[N], val[N], sum;

void update(int x, int v) {
    if(x == 0) return;
    for(; x <= n; x += x & -x) T[x] += v;
}

long query(int x) {
    long v = 0;
    for(; x > 0; x -= x & -x) v += T[x];
    return v;
}

long f(long a, long b) {
    a = query(a), b = query(b);
    if(a < b) return (a - b) * s;
    return (a - b) * t;
}

int main() {
    scanf("%d %d %d %d", &n, &q, &s, &t);
    for(int i = 0, v; i <= n; ++i) scanf("%d", &v), update(i, v), update(i+1, -v);
    for(int i = 0; i < n; ++i) val[i] = f(i, i+1), sum += val[i];
    for(int i = 0, a, b, c; i < q; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        sum -= f(a-1, a) + (b == n ? 0 : f(b, b+1));
        update(a, c), update(b+1, -c);
        sum += f(a-1, a) + (b == n ? 0 : f(b, b+1));
        printf("%lld\n", sum);
    }
}