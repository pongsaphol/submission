#include <bits/stdc++.h>
using namespace std;

char A[15];

int n, val;

int main() {
    scanf("%d", &n);
    sprintf(A, "%d", n);
    for(int i = 0; A[i]; ++i) val += A[i] - '0';
    puts(n % val ? "No" : "Yes");
}