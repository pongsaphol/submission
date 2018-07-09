#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, mx = 0, mn = 1e9;
    cin >> n;
    for(int i = 0, z; i < n; ++i) {
        cin >> z;
        mx = max(mx, z), mn = min(mn, z);
    }
    cout << mx - mn << endl;
}