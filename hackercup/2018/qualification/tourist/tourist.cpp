#include <bits/stdc++.h>
#define long long long
using namespace std;

void solve() {
    long n, k, v;
    cin >> n >> k >> v;
    int stpos = (k * (v-1)) % n;
    bitset<100> pos;
    for(; k; k--, stpos++, stpos %= n) pos[stpos] = true;
    for(int i = 0; i < n; ++i) {
        string str; cin >> str;
        if(pos[i]) cout << str << ' ';
    }
}

int main() {
    int T; cin >> T;
    for(int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
        puts("");
    }
}