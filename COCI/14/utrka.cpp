#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<string> S;
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        string now; cin >> now;
        S.emplace(now);
    }
    for(int i = 1; i < n; ++i) {
        string now; cin >> now;
        S.erase(S.find(now));
    }
    cout << *S.begin() << '\n';
}
