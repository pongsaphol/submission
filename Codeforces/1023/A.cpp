#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m; 
char A[N], B[N];

int main() {
    scanf("%d %d", &n, &m);
    scanf(" %s %s", A, B);
    int i, j;
    for(i = 0; A[i] != '*'; ++i) if(A[i] != B[i]) return !printf("NO");
    reverse(A, A+n), reverse(B, B+m);
    for(j = 0; A[j] != '*'; ++j) if(A[j] != B[j]) return !printf("NO");
    reverse(A, A+n), reverse(B, B+m);
    j = m-j-1;

    if(i > j+1) return !printf("NO");
    for(int k = i; k <= j; ++k) if(!(B[i] >= 'a' && B[i] <= 'z')) return !printf("NO");
    puts("YES");
}