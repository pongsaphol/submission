#include <bits/stdc++.h>
using namespace std;

#define long long long

long num(char* A, int v) {
    if(A[0] == 0 || v == 0 || A[0] == '0') return 0;
    int dp[4] = {0, 0, 0, 0};
    dp[0] = 1, dp[1] = A[0]-'0'-1;
    if(A[1] != 0)
        for(int i = 1; A[i]; ++i) {
            for(int j = v; j; --j) {
                dp[j] += dp[j-1] * 9;
    }}
    long ans = 0;
    for(int j = 1;; ++j) 
        if(A[j] != '0') {
            ans += num(A+j, v-1); break;
        }
    for(int i = 0; i <= v; ++i) ans += dp[i];
    return ans;
}

int main() {
   int tc; scanf("%d", &tc);
   while(tc--) {
        long a, b; scanf("%lld %lld", &a, &b);
        a--;
        char A[100], B[100];
        sprintf(A, "%lld", a), sprintf(B, "%lld", b);
        printf("%lld\n", num(B, 3)-num(A, 3));
   }
}
