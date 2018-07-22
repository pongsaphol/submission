#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> V;
    multiset<int> S;
    for(int i = 0, a; i < n; ++i) {
        scanf("%d", &a);
        V.emplace_back(a);
        S.emplace(a);
    }
    sort(V.begin(), V.end(), greater<int>());
    int cnt = 0;
    for(auto x : V) {
        auto it = S.upper_bound(x);
        if(it != S.end()) S.erase(it), cnt++;
    }
    printf("%d\n", cnt);
}