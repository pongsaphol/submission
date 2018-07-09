#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    vector<int> L, R;
    for(int i = 1; i <= n; ++i) {
        int ret; scanf("%d", &ret);
        if(i <= (n>>1)) L.emplace_back(ret);
        else R.emplace_back(ret);
    }
    vector<int> lhs;
    for(int i = 0; i < (1<<L.size()); ++i) {
        int sum = 0;
        for(int j = 0; j < L.size(); ++j) if(i >> j & 1) sum = (sum + L[j]) % m;
        lhs.emplace_back(sum);
    }
    sort(lhs.begin(), lhs.end());
    int mx = *max_element(lhs.begin(), lhs.end());
    for(int i = 0; i < (1<<R.size()); ++i) {
        int sum = 0;
        for(int j = 0; j < R.size(); ++j) if(i >> j & 1) sum = (sum + R[j]) % m;
        mx = max(mx, sum);
        int ret = m - sum;
        auto it = lower_bound(lhs.begin(), lhs.end(), ret);
        if(it != lhs.begin()) it--;
        mx = max(mx, (sum + *it) % m);
    }
    printf("%d\n", mx);
}