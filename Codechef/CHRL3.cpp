#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    multiset<int> S;
    for(int i = 0, val; i < n; ++i) {
        scanf("%d", &val);
        auto it = S.upper_bound(val);
        if(it != S.begin()) {
            it--;
            S.erase(it);
        }
        S.emplace(val);
    }
    printf("%d\n", (int)S.size());
}
