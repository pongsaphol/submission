#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int MX = 1e6;

int n, m, A[N];
int t[MX];

void update(int x, int v) {
    for(; x <= MX; x += x & -x) t[x-1] += v;
}

int query(int x) {
    int v = 0;
    for(; x; x -= x & -x) v += t[x-1];
    return v;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    for(int i = 1; i < n; ++i) {
        update(min(A[i], A[i+1]), 1);
        update(1+max(A[i], A[i+1]), -1);
    } 
    for(int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d", &a, &b);
        if(a == 1) {
            scanf("%d", &c);
            if(b != 1) {
                update(min(A[b], A[b-1]), -1);
                update(1+max(A[b], A[b-1]), 1);
                update(min(c, A[b-1]), 1);
                update(1+max(c, A[b-1]), -1);
            }
            if(b != n) {
                update(min(A[b], A[b+1]), -1);
                update(1+max(A[b], A[b+1]), 1);
                update(min(c, A[b+1]), 1);
                update(1+max(c, A[b+1]), -1);
            }
            A[b] = c;
        } else printf("%d\n", query(b)); 
    }
    
}