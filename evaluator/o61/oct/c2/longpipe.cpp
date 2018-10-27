#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 5e5+5;
const long M = 1e9+7;

//long dp[N][3];

long add(long a, long b, long c) { return (a + b + c + M + M + M) % M;} 
vector<vector<long> > mat = 
{{2, 1, 0, -1, -1, 1}, 
 {1, 2, 1, -1, -1, -1}, 
 {0, 1, 2, 1, -1, -1}, 
 {1, 0, 0, 0, 0, 0}, 
 {0, 1, 0, 0, 0, 0}, 
 {0, 0, 1, 0, 0, 0}};

 vector<vector<long> > mul(vector<vector<long> > &a, vector<vector<long> > &b) {
     vector<vector<long> > ret(6, vector<long>(6, 0));
     for(int i = 0; i < 6; ++i) for(int j = 0; j < 6; ++j) for(int k = 0; k < 6; ++k) {
         ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % M;
     }
     return ret;
 }

vector<vector<long> > dp[32];
vector<vector<long> > iden =
{{1, 0, 0, 0, 0, 0},
 {0, 1, 0, 0, 0, 0}, 
 {0, 0, 1, 0, 0, 0},
 {0, 0, 0, 1, 0, 0},
 {0, 0, 0, 0, 1, 0},
 {0, 0, 0, 0, 0, 1}};

int main() {
    dp[0] = mat;
    int n; scanf("%d", &n);
    for(int i = 1; i < 31; ++i) dp[i] = mul(dp[i-1], dp[i-1]);
    for(int i = 0; i <= 30; ++i) if(n >> i & 1) iden = mul(iden, dp[i]);
    vector<long> st = {1, 1, 1, 0, 0, 0};
    vector<long> ans(6);
    for(int i = 0; i < 6; ++i) for(int j = 0; j < 6; ++j) {
        ans[i] = (ans[i] + iden[i][j] * st[j]) % M;
    }
    return !printf("%lld\n", (add(ans[0], ans[1], ans[2]) + add(-ans[3], -ans[4], -ans[5])) % M);
}
