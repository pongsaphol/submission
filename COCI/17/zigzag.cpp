#include <bits/stdc++.h>
using namespace std;

vector<string> A[26];
int n, m, cnt[26];

int main() {
    cin >> n >> m;
    while(n--) {
        string ret; cin >> ret;
        A[ret[0]-'a'].emplace_back(ret);
    }
    for(int i = 0; i < 26; ++i) sort(A[i].begin(), A[i].end());
    while(m--) {
        char c; cin >> c;
        cout << A[c-'a'][cnt[c-'a']] << endl;
        cnt[c-'a'] = (cnt[c-'a'] + 1) % A[c-'a'].size();
    }
}