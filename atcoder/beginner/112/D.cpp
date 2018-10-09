#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<int> frac;
    for(int i = 1; i*i <= m; ++i) {
        if(i * i == m) frac.emplace_back(i);
        else if(m % i == 0) frac.emplace_back(i), frac.emplace_back(m / i);
    }
    sort(frac.begin(), frac.end(), greater<int>());
    for(auto x : frac) if(m / x >= n) return !printf("%d\n", x);
}
