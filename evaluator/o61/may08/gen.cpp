#include <bits/stdc++.h>
using namespace std;

char A[1030][1030];

int main() {
    int n; scanf("%d", &n);
    int a, b, c, d;
    while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF) {
        swap(c, d);
        if(a != 1) A[c][d] = b+'0';
        if(a != 2) A[c][d+1] = b+'0';
        if(a != 3) A[c+1][d] = b+'0';
        if(a != 4) A[c+1][d+1] = b+'0';
    }
    n = 1 << n;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        if(!A[i][j]) A[i][j] = 'X';
    }
    for(int i = 1; i <= n; ++i) puts(A[i]+1);
}
