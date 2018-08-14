#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int n, A[3], dp[1001][3][8];
vector<int> g[3] = {{2}, {0}, {0, 1}};

void setVal(int &a, int b) {
    a = (a + b) % M;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < 3; ++i) scanf("%d", A+i);
    for(int i = 1; i <= A[0]; ++i) dp[i][0][1] = 1;
    for(int i = 2; i <= n; ++i) for(int j = 0; j < 3; ++j) {
        for(int k = max(0, i - A[j]); k < i; ++k) for(auto v : g[j]) 
            for(int bit = 0; bit < 8; ++bit) setVal(dp[i][j][bit|(1<<j)], dp[k][v][bit]);
    }
    int sum = 0;
    for(int i = 0; i < 3; ++i) setVal(sum, dp[n][i][7]);
    printf("%d\n", sum);
}
