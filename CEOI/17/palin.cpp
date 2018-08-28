#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e6+5;

char A[N];
pii d[N], iden(131, 133);

pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
pii mul(pii a, pii b) { return pii(a.x * b.x, a.y * b.y); }

void solve() {
    scanf("%s", A);
    int n = strlen(A), cnt = 0;
    pii lhs, rhs;
    for(int i = 0, p = 0; i < n; ++i, ++p) {
        lhs = add(pii(A[i], A[i]), mul(iden, lhs));
        rhs = add(rhs, mul(pii(A[n-i-1], A[n-i-1]), d[p]));
        if(lhs == rhs) cnt++, p = -1, lhs = rhs = pii(0, 0);
    }
    printf("%d\n", cnt);
}

int main() {
    d[0] = pii(1, 1);
    for(int i = 1; i < N; ++i) d[i] = mul(d[i-1], iden);
    int T; scanf("%d", &T);
    while(T--) solve();
}