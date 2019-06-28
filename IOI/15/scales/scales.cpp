#include "scales.h"

#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

vector<pair<int, vector<int> > > que;
vector<vector<int> > perm;
int ids[] = {0, 107, 107, 107, 49, 48, 46, 45, 44, 42, 38, 37, 35, 88, 95, 28, 67, 74, 15, 8, 40, 40, 85, 95, 28, 64, 74, 15, 11, 40, 40, 85, 88, 28, 64, 67, 15, 11, 33, 33, 31, 11, 9, 31, 11, 9, 10, 52, 52, 31, 24, 22, 31, 24, 22, 23, 52, 52, 72, 99, 79, 29, 18, 70, 29, 83, 5, 34, 8, 6, 34, 8, 6, 52, 7, 52, 34, 21, 19, 34, 21, 19, 52, 20, 52, 72, 103, 83, 32, 18, 69, 32, 79, 5, 41, 5, 3, 41, 5, 3, 55, 55, 4, 41, 18, 16, 41, 18, 16, 55, 55, 17, 103, 79, 83, 39, 21, 76, 39, 72, 8, 75, 55, 75, 65, 65, 55, 75, 18, 31, 68, 52, 68, 65, 65, 52, 18, 68, 31, 65, 65, 1, 8, 21, 58, 5, 75, 58, 96, 96, 55, 86, 86, 55, 96, 5, 31, 89, 89, 52, 86, 86, 52, 5, 89, 31, 86, 86, 1, 8, 8, 58, 5, 73, 58, 96, 16, 18, 58, 52, 68, 18, 52, 22, 68, 52, 65, 55, 96, 96, 55, 58, 8, 66, 86, 52, 21, 21, 86, 55, 75, 75, 75, 58, 75, 68, 68, 58, 75, 18, 34, 65, 52, 65, 68, 68, 52, 18, 65, 34, 19, 6, 55, 68, 68, 1, 75, 5, 55, 96, 96, 58, 89, 89, 58, 96, 5, 34, 86, 86, 52, 89, 89, 52, 5, 86, 34, 6, 6, 55, 89, 89, 1, 73, 5, 55, 16, 96, 18, 55, 52, 65, 18, 52, 19, 65, 52, 68, 96, 58, 96, 55, 55, 11, 63, 89, 52, 24, 24, 89, 75, 58, 75, 68, 58, 68, 75, 75, 58, 68, 21, 41, 65, 55, 65, 75, 75, 55, 21, 65, 41, 16, 3, 52, 68, 3, 52, 75, 75, 1, 89, 89, 58, 96, 96, 58, 89, 8, 41, 86, 86, 55, 96, 96, 55, 8, 86, 41, 3, 3, 52, 66, 3, 52, 96, 96, 1, 55, 52, 65, 16, 89, 21, 52, 21, 16, 65, 55, 75, 89, 58, 89, 52, 52, 11, 63, 96, 55, 24, 24, 96, 68, 58, 68, 0};
int mx = 0;
int zzz;

int dfs(int u, vector<int> vec, int lv) {
    if(vec.size() == 1) return vec[0];
    mx = max(mx, u);
    for(int ii = ids[u];;) {
        auto& z = que[ii];
        vector<int> Mp[6];
        int abc;
        if(z.x == 0) abc = getHeaviest(z.y[0]+1, z.y[1]+1, z.y[2]+1);
        if(z.x == 1) abc = getLightest(z.y[0]+1, z.y[1]+1, z.y[2]+1);
        if(z.x == 2) abc = getMedian(z.y[0]+1, z.y[1]+1, z.y[2]+1);
        if(z.x == 3) abc = getNextLightest(z.y[0]+1, z.y[1]+1, z.y[2]+1, z.y[3]+1);
        for(int v : vec) {
            vector<pii> val;
            for(int i = 0; i < 3; ++i) val.emplace_back(perm[v][z.y[i]], z.y[i]);
            sort(val.begin(), val.end());
            if(z.x == 0) 
                Mp[val[2].y].emplace_back(v);
            else if(z.x == 1)
                Mp[val[0].y].emplace_back(v);
            else if(z.x == 2)
                Mp[val[1].y].emplace_back(v);
            else {
                bool st = false;
                for(int i = 0; i < 3; ++i) {
                    if(val[i].x > perm[v][z.y[3]]) {
                        Mp[val[i].y].emplace_back(v);
                        st = true;
                        break;
                    }
                }
                if(!st) Mp[val[0].y].emplace_back(v);
            }

        } 
        int step = 0;
        for(int i = 0; i < 6; ++i) if(Mp[i].size()) {
            step++;
            if(i == abc-1)
                return dfs(u*3 + step, Mp[i], lv / 3);
        }
    }
    return false;
}

int nth = 6;

void init(int T) {
    for(int i = 0; i < (1 << nth); ++i) {
        vector<int> vec;
        for(int j = 0; j < nth; ++j) if(i >> j & 1) 
            vec.emplace_back(j);
        if(vec.size() == 3) 
            for(int j = 0; j < 3; ++j) que.emplace_back(j, vec);
        if(vec.size() == 4) {
            for(int i = 0; i < 4; ++i) {
                vector<int> ret;
                for(int j = 0; j < 4; ++j) if(i != j) ret.emplace_back(vec[j]);
                ret.emplace_back(vec[i]);
                que.emplace_back(3, ret);
            }
        }
    }
    vector<int> now;
    for(int i = 0; i < nth; ++i) now.emplace_back(i+1);
    do {
        perm.emplace_back(now);
    } while(next_permutation(now.begin(), now.end()));
}

void orderCoins() {
    int* ans = new int[6];
    vector<int> zz;
    for(int i = 0; i < perm.size(); ++i) zz.emplace_back(i);
    int k = dfs(0, zz, 2187);
    for(int i = 0; i < 6; ++i) ans[perm[k][i]-1] = i+1;
    answer(ans);
}