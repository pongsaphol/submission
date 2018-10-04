#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5, INF = 1e9;

int n, m, q, l = 1, cnt, want[N], freq[N], A[N];

int main() {
    scanf("%d %d %d", &n, &m, &q); 
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    for(int i = 0, a, b; i < q; ++i) {
        scanf("%d %d", &a, &b);
        want[a] = b;
    } 
    int mn = INF;
    for(int i = 1; i <= n; ++i) {
        if(++freq[A[i]] == want[A[i]]) cnt++;
        if(cnt == q) {
            while(freq[A[l]] != want[A[l]]) freq[A[l++]]--;
            mn = min(mn, i-l+1); 
        }
    }
    if(mn == INF) return !printf("impossible");
    printf("%d\n", mn);
}
