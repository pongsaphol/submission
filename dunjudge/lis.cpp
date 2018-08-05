#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> V;

int main() {
    scanf("%d", &n);
    for(int i = 1, ret; i <= n; ++i) {
        scanf("%d", &ret);
        auto it = lower_bound(V.begin(), V.end(), ret);
        if(it == V.end()) V.emplace_back(ret);
        else *it = ret; 
    }
    printf("%d\n", V.size());
}