#include <bits/stdc++.h>
using namespace std;

char A[6];

int main() {
    int n; scanf("%d", &n);
    while(1) {
        sprintf(A, "%d", n);
        if(A[0] == A[1] and A[1] == A[2]) break;
        n++;
    }
    printf("%d\n", n);
}
