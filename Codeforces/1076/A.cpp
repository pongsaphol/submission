#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n;
char A[N];

int main() {
    scanf("%d", &n);
    scanf("%s", A);
    for(int i = 0; i < n-1; ++i) if(A[i] > A[i+1]) {
        for(int j = 0; j < i; ++j) printf("%c", A[j]);
        for(int j = i+1; j < n; ++j) printf("%c", A[j]);
        return 0;
    }
    printf("%s", A+1);
}
