#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5, INF = 1e9;

int n, Ans, dp[2][256];
char A[N];

int get(char c) { return c == 'M' ? 1 : (c == 'F' ? 2 : 3); }

int getCost(int Prev, int Now) {
    int L1 = Prev >> 2;
    int L2 = Prev ^ (L1 << 2);
    int A[4] = {0, 0, 0, 0};
    A[L1] = 1, A[L2] = 1, A[Now] = 1;
    return A[1] + A[2] + A[3];
}

int main() {
    scanf("%d", &n);
    scanf("%s", A+1);
    fill(dp[0], dp[0] + 256, -INF);
    dp[0][0] = 0;
    for(int i = 1, pre = 0, now = 1; i <= n; ++i, swap(pre, now)) {
        fill(dp[now], dp[now] + 256, -INF);
        for(int j = 0; j < 256; ++j) {
            int First = j >> 4;
            int Second = j ^ (First << 4);
            int NewFirst = ((First >> 2) | (get(A[i]) << 2)) << 4 | Second;
            int NewSecond = (Second >> 2) | (get(A[i]) << 2) | (First << 4);
            dp[now][NewFirst] = max(dp[now][NewFirst], dp[pre][j] + getCost(First, get(A[i])));
            dp[now][NewSecond] = max(dp[now][NewSecond], dp[pre][j] + getCost(Second, get(A[i])));
        }
        if(i == n) for(int j = 0; j < 256; ++j) Ans = max(Ans, dp[now][j]);
    }
    printf("%d\n", Ans);
}