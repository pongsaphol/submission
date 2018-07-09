#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> S;
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        int ret; cin >> ret;
        if(ret) S.emplace(ret);
    }
    cout << S.size();
}
