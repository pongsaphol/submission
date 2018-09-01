#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) if(n % i == 0) {
        ret.emplace_back(i);
        if(i * i != n) ret.emplace_back(n / i);
    }
    sort(ret.begin(), ret.end());
    vector<vector<int> > d(ret.size());
    d[0].emplace_back(0);
    for(int i = 1; i < (int)ret.size(); ++i) {
        for(int j = 0; j < i; ++j) if(ret[i] % ret[j] == 0)
            for(auto x : d[j]) d[i].emplace_back(x + ret[i] / ret[j] - 1);
        sort(d[i].begin(), d[i].end());
        d[i].resize(unique(d[i].begin(), d[i].end()) - d[i].begin());
    }
    printf("%d\n", (int)d.back().size());
    for(int x : d.back()) printf("%d ", x);
}
