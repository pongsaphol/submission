#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m;
int A[N], B[N];

bool f(int x) {
    int last = 0;
    for(int i = 0; i < m; ++i) {
        if(last == n) return false;
        int ptr = lower_bound(A+last, A+n, B[i] - x) - A;
        if(ptr == n or abs(A[ptr] - B[i]) > x) return false;
        last = ptr+1;
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%d", A+i);
    for(int i = 0; i < m; ++i) scanf("%d", B+i);
    if(n < m) {
        for(int i = 0; i < m; ++i) swap(A[i], B[i]);
        swap(n, m);
    }
    sort(A, A+n), sort(B, B+m);
    int l = 0, r = 1e9;
    while(l < r) {
        int m = (l + r) >> 1;
        if(f(m)) r = m;
        else l = m+1;
    }
    printf("%d\n", r);
}
