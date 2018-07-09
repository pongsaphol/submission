#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m, A[N], pref[N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", A+i);
        pref[i] = pref[i-1];
        if(i % 2) pref[i] += A[i] - A[i-1];
    } 
    n++;
    pref[n] = pref[n-1];
    if(n % 2) pref[n] += m - A[n-1];
    A[n] = m;
    int ans = max(pref[n], m - pref[n]);
    for(int i = 1; i <= n; ++i) {
        if(A[i] + 1 != A[i+1]) ans = max(ans, pref[i] + A[n] - A[i] - pref[n] + pref[i] + (i % 2 ? -1 : 0));
        if(A[i] - 1 != A[i-1]) ans = max(ans, pref[i] + m - A[i] - pref[n] + pref[i] + (i % 2 ? -1 : 0));
    }
    printf("%d\n", ans);
}