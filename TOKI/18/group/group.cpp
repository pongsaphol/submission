#include "group.h"
#include <bits/stdc++.h>
using namespace std;

int getMinimumDelay(int n, vector<int> x, vector<int> y) {
    long long mnx, mny, mxx, mxy;
    mnx = mny = 2e9, mxx = mxy = -2e9;
    for(int i = 0; i < n; ++i) {
        x[i] = x[i] + y[i];
        y[i] = x[i] - 2 * y[i];
        mnx = min(mnx, (long long)x[i]), mny = min(mny, (long long)y[i]);
        mxx = max(mxx, (long long)x[i]), mxy = max(mxy, (long long)y[i]);
    }
    long long l = 0, r = 2e9;
    while(l < r) {
        long long m = l + r >> 1;
        bool st1 = true, st2 = true;
        for(int i = 0; i < n; ++i) {
            st1 &= (x[i] <= mnx + m && y[i] <= mny + m) || (x[i] >= mxx - m && y[i] >= mxy - m);
            st2 &= (x[i] <= mnx + m && y[i] >= mxy - m) || (x[i] >= mxx - m && y[i] <= mny + m);
        }
        if(st1 || st2) r = m;
        else l = m + 1;
    }
    return (int)r;
}
