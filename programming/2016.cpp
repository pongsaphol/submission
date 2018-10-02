#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 5e4+5;

int n, k;
long r, dp[N][15][4];
char A[N], ent[] = "NACGT";
int trop[128];

int main() {
    scanf("%d %d %lld", &n, &k, &r);
    scanf("%s", A+1);
    dp[n+1][1][3] = 1;
    for(int i = 0; i < 5; ++i) trop[ent[i]] = i-1;
    for(int i = n; i > 0; --i) {
        A[i] = trop[A[i]];
        for(int j = 1; j <= k; ++j) for(int pv = 0; pv < 4; ++pv) {
            if(~A[i]) dp[i][j][A[i]] += dp[i+1][j - (pv < A[i])][pv];
            else for(int z = 0; z < 4; ++z) dp[i][j][z] += dp[i+1][j - (pv < z)][pv];
        } 
    }
    long ret = 0;
    int skip = 0;
    for(int i = 1; i <= n; ++i) {
        if(~A[i]) skip += A[i] < A[i-1];
        else for(int z = 0; z < 4; ++z) {
            long sum = 0;
            for(int j = 1; j + skip + (z < A[i-1]) <= k; ++j) sum += dp[i][j][z];
            if(sum + ret >= r) {
                skip += (z < A[i-1]), A[i] = z;
                break;
            }else ret += sum;
        }
    }
    for(int i = 1; i <= n; ++i) printf("%c", ent[A[i]+1]);
    puts("");
}
