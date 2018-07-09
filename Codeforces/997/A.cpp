#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 3e5+5;

char A[N];

int main() {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    scanf("%s", A);
    bool st = true;
    int cnt = 0;
    for(int i = 0; A[i]; ++i) {
        if(A[i] == '0') cnt += st, st = false;
        else st = true;
    } 
    long mn = 1e18;
    if(cnt == 0) mn = 0;
    for(int i = 0; i < cnt; ++i) mn = min(mn, 1ll * x * i + 1ll * (cnt - i) * y);
    printf("%lld\n", mn);
}