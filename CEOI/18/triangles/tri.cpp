#include <bits/stdc++.h>
#include "trilib.h"
using namespace std;

int n;
int val;

vector<int> convex_hull(vector<int> &V) {
    vector<int> ret;
    bool st = false;
    for(auto x : V) {
        if(ret.size() < 2) {
            ret.emplace_back(x);
            continue;
        }
        while(ret.size() >= 2 and is_clockwise(ret[ret.size()-2], ret.back(), x)) ret.pop_back();
        ret.emplace_back(x);
    }
    return ret;
}

int main() {
    n = get_n();
    vector<int> L, R;
    for(int i = 3; i <= n; ++i) if(is_clockwise(1, 2, i)) L.emplace_back(i); else R.emplace_back(i);
    sort(L.begin(), L.end(), [&](const int &a, const int &b) { return !is_clockwise(1, a, b); });
    sort(R.begin(), R.end(), [&](const int &a, const int &b) { return !is_clockwise(1, a, b); });
    L.emplace_back(2), R.emplace_back(1);
    L = convex_hull(L), R = convex_hull(R);    
    vector<int> ret;
    for(auto x : L) ret.emplace_back(x);
    for(auto x : R) ret.emplace_back(x);
    ret = convex_hull(ret);
    list<int> l; for(auto x : ret) l.push_back(x);
    bool status = true;
    while(status) {
        status = false;
        int a = l.back(); l.pop_back();
        if(is_clockwise(l.back(), a, l.front())) status = true;
        else l.push_back(a);
        a = l.front(); l.pop_front();
        if(!is_clockwise(l.front(), a, l.back())) status = true;
        else l.push_front(a);
    }
    give_answer((int)l.size());
}