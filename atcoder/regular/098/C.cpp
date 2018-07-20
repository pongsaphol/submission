#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;

int n, qs[N];
char A[N];

int main() {
    scanf("%d", &n);
    scanf("%s", A+1);
    for(int i = 1; i <= n; ++i) qs[i] = qs[i-1] + (A[i] == 'E');
    int mx = N;
    for(int i = 1; i <= n; ++i) 
        mx = min(mx, i-1-qs[i-1] + qs[n]-qs[i]);
    printf("%d\n", mx);
}