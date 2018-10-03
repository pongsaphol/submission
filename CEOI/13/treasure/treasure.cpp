#include "treasure.h"
#include <bits/stdc++.h>
using namespace std;


int ans[105][105];
bool have[105][105];

void findTreasure (int N) {
    int m = N >> 1;
    for(int i = m; i <= N; ++i) for(int j = m; j <= N; ++j) ans[i][j] = countTreasure(1, 1, i, j);
    for(int i = m+1; i <= N; ++i) for(int j = m+1; j <= N; ++j) have[i][j] = ans[i][j] - ans[i-1][j] - ans[i][j-1] + ans[i-1][j-1];
    for(int i = 1; i <= m+1; ++i) for(int j = m; j <= N; ++j) ans[i][j] = countTreasure(i, 1, N, j);
    for(int i = 1; i <= m; ++i) for(int j = m+1; j <= N; ++j) have[i][j] = ans[i][j] - ans[i+1][j] - ans[i][j-1] + ans[i+1][j-1];
    for(int i = m; i <= N; ++i) for(int j = 1; j <= m+1; ++j) ans[i][j] = countTreasure(1, j, i, N);
    for(int i = m+1; i <= N; ++i) for(int j = 1; j <= m; ++j) have[i][j] = ans[i][j] - ans[i-1][j] - ans[i][j+1] + ans[i-1][j+1];
    for(int i = 1; i <= m+1; ++i) for(int j = 1; j <= m+1; ++j) ans[i][j] = countTreasure(i, j, N, N);
    for(int i = 1; i <= m; ++i) for(int j = 1; j <= m; ++j) have[i][j] = ans[i][j] - ans[i+1][j] - ans[i][j+1] + ans[i+1][j+1];
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) if(have[i][j]) Report(i, j);
}
