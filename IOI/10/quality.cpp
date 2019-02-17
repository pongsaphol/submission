#include "grader.h"

int dp[3001][3001];

int rectangle(int R, int C, int H, int W, int Q[3001][3001]) {
    int l = 1, r = R*C;
    auto f = [&](int mid) {
        for(int i = 1; i <= R; ++i) for(int j = 1; j <= C; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (Q[i-1][j-1] <= mid ? 1 : 0);
            if(i >= H and j >= W) if(dp[i][j] - dp[i-H][j] - dp[i][j-W] + dp[i-H][j-W] >= (W*H+1)/2)
                return true;
        }
        return false;
    };
    while(l < r) {
        int mid = l + r >> 1;
        if(f(mid)) r = mid;
        else l = mid + 1;
    }
    return r;
}
