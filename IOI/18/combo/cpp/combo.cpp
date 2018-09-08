#include "combo.h"
#include <bits/stdc++.h>
using namespace std;

string guess_sequence(int n) {
    string ans;
    if(press("AB")) if(press("A")) ans += 'A'; else ans += 'B';
    else if(press("X")) ans += 'X'; else ans += 'Y';
    vector<char> ent, pre = {'X', 'Y', 'A', 'B'};
    for(int i = 0; i < 4; ++i) if(pre[i] != ans[0]) ent.emplace_back(pre[i]);
    for(int i = 2; i < n; ++i) {
        int val = press(ans + ent[0] + ans + ent[1] + ent[0] + ans + ent[1] + ent[1] + ans + ent[1] + ent[2]);
        if(val == (int)ans.size()) ans.push_back(ent[2]);
        else if(val == (int)ans.size() + 1) ans.push_back(ent[0]);
        else ans.push_back(ent[1]);
    }
    if(n != 1) {    
        if(press(ans + ent[0]) == n) ans += ent[0];
        else if(press(ans + ent[1]) == n) ans += ent[1];
        else ans += ent[2];
    }
    return ans;
}
