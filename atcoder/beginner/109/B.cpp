#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> S;
    int n; cin >> n;
    char last;
    string ret; cin >> ret;
    S.emplace(ret);
    last = ret.back();
    for(int i = 1; i < n; ++i) {
        cin >> ret;
        if(ret[0] != last || S.find(ret) != S.end()) return !printf("No");
        last = ret.back();
        S.emplace(ret);
    }
    puts("Yes");
}
