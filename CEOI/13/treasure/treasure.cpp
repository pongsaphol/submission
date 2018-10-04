#include "treasure.h"
#include <bits/stdc++.h>
using namespace std;

int pref[105][105];
bool have[105][105];

void findTreasure (int N) {
    int m = N >> 1;
    for(int i = N; i; --i) for(int j = N; j; --j) {
        if(i > m and j > m) pref[i][j] = countTreasure(1, 1, i, j);
        if(i <= m and j > m) pref[i][j] = pref[N][j] - countTreasure(i+1, 1, N, j);
        if(i > m and j <= m) pref[i][j] = pref[i][N] - countTreasure(1, j+1, i, N);
        if(i <= m and j <= m) pref[i][j] = pref[N][j] + pref[i][N] - pref[N][N] + countTreasure(i+1, j+1, N, N);
    }
    for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) if(pref[i][j] - pref[i-1][j] - pref[i][j-1] + pref[i-1][j-1]) Report(i, j);
}
