#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> M;
    int n; cin >> n;
    vector<int> V;
    for(int i = 1, val; i <= n; ++i) {
        cin >> val; val -= i;
        V.emplace_back(val);
    }
    sort(V.begin(), V.end());
    int m = V[n>>1];
    long long sum = 0;
    for(auto x : V) sum += abs(x - m);
    cout << sum;
}