#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> V;
    int n; scanf("%d", &n);
    for(int i = 0, ret; i < n; ++i) {
        scanf("%d", &ret);
        V.emplace_back(ret);
    }
    sort(V.begin(), V.end(), greater<int>());
    for(auto x : V) {
        printf("%d", x);
        if(--n) printf(" ");
    }
}