#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;
    vector<int> V;
    for(int i = 0; i < n; ++i) {
        int ret; scanf("%d", &ret);
        V.emplace_back(ret);
    }
    sort(V.begin(), V.end());
    cout << V[2] - V[0];
}