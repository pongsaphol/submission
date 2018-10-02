#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; scanf("%d", &n);
    vector<int> A(n+1);
    for(int i = 1, ret; i <= n; ++i) scanf("%d", &ret), A[i] = ret;
    if(n % 2) return void(puts("NO"));
    int z = n / 2;
    for(int i = 1; i <= z; ++i) {
        if(A[i] == -1 and A[i+z] == -1) A[i] = A[i+z] = 1;
        if(A[i] == -1) A[i] = A[i+z];
        if(A[i+z] == -1) A[i+z] = A[i];
        if(A[i] != A[i+z]) return void(puts("NO"));
    }
    puts("YES");
    for(int i = 1; i <= n; ++i) printf("%d ", A[i]);
}

int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
}
