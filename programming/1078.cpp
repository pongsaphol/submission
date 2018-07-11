#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, A[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) scanf("%d", A+i);
    sort(A, A+n);
    long long sum = 0;
    int z = n >> 1;
    for(int i = 0; i < z; ++i) sum += A[n-i-1] - A[i];
    cout << sum;
}