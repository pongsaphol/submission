#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, k, f[26];
char A[N];

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", A);
    for(int i = 0; i < n; ++i) f[A[i] - 'A']++;
    int mn = 1e9;
    for(int i = 0; i < k; ++i) mn = min(mn, f[i]);
    printf("%d\n", mn * k);
}
