#include "molecules.h"
#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

vector<int> find_subset(int l, int u, vector<int> w) {
    vector<pii> ret;
    for(int i = 0; i < w.size(); ++i) ret.emplace_back(w[i], i);
    sort(ret.begin(), ret.end());
    int s = ret.size();
    long sm = 0, bg = 0;
    for(int i = 0; i < s; ++i) {
        sm += ret[i].x, bg += ret[s-i-1].x;
        long sum = 0;
        if(l <= bg && sm <= u) for(int j = 0; j < s; ++j) {
            sum += ret[j].x;
            if(j > i) sum -= ret[j-i-1].x;
            if(l <= sum && sum <= u) {
                vector<int> ans;
                for(int k = j; k >= j-i; --k) ans.emplace_back(ret[k].y);
                return ans;
            } 
        }
    }
    return vector<int>();
}
