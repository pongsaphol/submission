#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    for(int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        string str; cin >> str;
        bool st = true;
        for(int i = 1; i < str.size(); ++i) {
            if(str[0] != str[i]) continue;
            string ret;
            for(int j = 0; j < i; ++j) ret.push_back(str[j]);
            ret = ret + str;
            string z = ret;
            z.resize(str.size());
            if(str != z) {
                st = false, cout << ret;
                break;
            }
        }
        if(st) cout << "Impossible";
        cout << endl;
    }
}