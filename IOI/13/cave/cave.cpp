#include "cave.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

bool wasHave[N];
int pos[N], status[N];
int cnt, pushToFunction[N];

void exploreCave(int n) {
    vector<int> V;
    for(int i = 0; i < n; ++i) V.emplace_back(i);
    for(int i = 0; i < n; ++i) {
        if(tryCombination(pushToFunction) == i) for(auto x : V) pushToFunction[x] ^= 1;
        int l = 0, r = n-i;
        while(l < r) {
            int m = (l + r) >> 1;
            for(int j = l; j <= m; ++j) pushToFunction[V[j]] ^= 1;
            if(tryCombination(pushToFunction) == i) r = m;
            else l = m + 1;
            for(int j = l; j <= m; ++j) pushToFunction[V[j]] ^= 1;
        }
        pos[V[r]] = i, status[V[r]] = pushToFunction[V[r]];
        V.erase(V.begin() + r);
    }
    answer(status, pos);
}
