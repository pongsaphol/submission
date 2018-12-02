#include <bits/stdc++.h>
#define iii tuple<int, int, bool>
#include "coprobber.h"
using namespace std;

int pos = -1, mv[MAX_N][MAX_N], gnum[MAX_N][MAX_N][2]; // cop, rob, 0 = cop, 1 = rob
bool check[MAX_N][MAX_N][2];
queue<iii> Q;

int start(int n, bool A[MAX_N][MAX_N]) {
    memset(mv, -1, sizeof mv);
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        for(int j = 0; j < n; ++j) cnt += A[i][j];
        for(int j = 0; j < n; ++j) {
            gnum[i][j][0] = 1;
            gnum[j][i][1] = cnt;
        }
        Q.emplace(i, i, 0), Q.emplace(i, i, 1);
        check[i][i][0] = check[i][i][1] = true;
        mv[i][i] = i;
    }
    while(!Q.empty()) {
        int c, r, st; tie(c, r, st) = Q.front(); Q.pop();
        if(st) {  // now is rob and cop move turn
            for(int i = 0; i < n; ++i) if((A[i][c] or i == c) and !check[i][r][0])
                if(!--gnum[i][r][0]) Q.emplace(i, r, 0), mv[i][r] = c, check[i][r][0] = true;
        } else {// now is cop and rob move turn
            for(int i = 0; i < n; ++i) if(A[r][i] and !check[c][i][1])
                if(!--gnum[c][i][1]) Q.emplace(c, i, 1), check[c][i][1] = true;
        }
    }
    for(int i = 0; i < n; ++i) {
        bool st = true;
        for(int j = 0; j < n; ++j) if(mv[i][j] == -1) st = false;
        if(st) pos = i;
    }
    return pos;
}

int nextMove(int R) {
    return pos = mv[pos][R];
}
