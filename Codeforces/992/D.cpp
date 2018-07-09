#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 2e5+5;

int n, k, ans;
long A[N];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    for(int i = 1; i <= n; ++i) {
        long mul = 1, sum = 0;
        for(int j = i; j <= n and j <= i + 60; ++j) {
            int l = log(mul), r = log(A[j]);
            if(l + r >= 18) break;
            mul *= A[j], sum += A[j];
            if(mul % sum == 0) if(mul / sum == k) ans++;
        }
    }
    printf("%d\n", ans);
}