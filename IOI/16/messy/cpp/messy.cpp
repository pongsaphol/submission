#include <bits/stdc++.h>
#include "messy.h"
using namespace std;

vector<int> restore_permutation(int n, int w, int r) {
    int lv = log2(n) - 1;
    for(int i = lv; ~i; --i) {
        for(int j = 0; j < n; ++j) if(j >> i & 1) {
            string str(n, '1');
            for(int k = 0; k < n; ++k) if((k >> i) == (j >> i) || (k >> i) == ((j >> i) ^ 1)) str[k] = '0';
            str[j] = '1';
            add_element(str);
        }
    }
    compile_set();
    vector<vector<int> > vec(n); 
    for(int i = 0; i < n; ++i) vec[0].emplace_back(i);
    for(int i = 0; i <= lv; ++i) {
        vector<vector<int> > now(n);
        for(int j = 0; j < (1 << i); ++j) {
            for(auto v : vec[j]) {
                string str(n, '1');
                for(auto vv : vec[j]) if(vv != v) str[vv] = '0';
                now[j << 1 | (check_element(str) ? 1 : 0)].emplace_back(v);
            }
        }
        vec = now;
    }
    vector<int> ans(n);
    for(int i = 0; i < n; ++i) ans[vec[i][0]] = i;
    return ans;
    return ans;
}
