#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> V[4];
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
        int ret; scanf("%d", &ret);
        V[(i & 1) | ((j & 1) << 1)].emplace_back(ret);
    }
    for(int i = 0; i < 4; ++i) sort(V[i].begin(), V[i].end());
    int z = (n * n)>> 2;
    int sum = 0;
    for(int i = 0; i < z; ++i) {
        int ret = 1;
        for(int j = 0; j < 4; ++j) ret *= V[j][i];
        sum += ret;
    }
    cout << sum << endl;
}