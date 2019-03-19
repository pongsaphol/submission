#include <bits/stdc++.h>
#include "sockslib.h"
using namespace std;

int n;

void matchs(int a, int b) {
    match(a, b);
}

int asks(vector<int> &vec) {
    int num = ask(vec);
    return num;
}


int main() {
    n = num();
    vector<int> vec;
    for(int i = 1; i <= 2*n; ++i) {
        vec.emplace_back(i);
        if(asks(vec) == vec.size()) continue;
        int l = 0, r = vec.size()-2;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            vector<int> nv;
            for(int i = mid; i < vec.size(); ++i) nv.emplace_back(vec[i]);
            if(asks(nv) != nv.size()) l = mid;
            else r = mid-1;
        }
        matchs(vec[l], i);
        vec.erase(find(vec.begin(), vec.end(), vec[l]));
        vec.resize(vec.size()-1);
    }
}
