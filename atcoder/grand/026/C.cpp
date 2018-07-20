#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

pii iden(131, 133), dp[16];

pii mul(pii a, pii b) { return pii(a.x * b.x, a.y * b.y); }
pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
pii sub(pii a, pii b) { return pii(a.x - b.x, a.y - b.y); }

int main() {
    dp[0] = pii(1, 1);
    for(int i = 1; i < 18; ++i) dp[i] = mul(dp[i-1], iden);
    int n; scanf("%d", &n);
    char A[40]; scanf("%s", A);
    map<pii, int> M;
    for(int i = 0; i < (1 << n); ++i) {
        int p1 = n, p2 = 0;
        pii r1, r2;
        for(int j = 0; j < n; ++j) 
            if(i >> j & 1) r1 = add(r1, mul(pii(A[j], A[j]), dp[--p1]));  
            else r2 = add(r2, mul(pii(A[j], A[j]), dp[p2++]));  
        M[sub(r1, r2)]++;
    } 
    for(int i = 0; i < n; ++i) A[i] = A[i + n];
    long long sum = 0;
    for(int i = 0; i < (1 << n); ++i) {
        int p1 = 0, p2 = n;
        pii r1, r2;
        for(int j = n-1; ~j; --j) 
            if(i >> j & 1) r1 = add(r1, mul(pii(A[j], A[j]), dp[p1++]));  
            else r2 = add(r2, mul(pii(A[j], A[j]), dp[--p2]));  
        sum += M[sub(r2, r1)];
    }
    printf("%lld\n", sum);
}
