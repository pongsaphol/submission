#include <bits/stdc++.h>
using namespace std;

#define iii tuple<int, int, int>

vector<iii> V;
bool chk[20];

int main() {
    int l; cin >> l;
    l--;
    int pv = -1;
    int sum = 0;
    int st = -1;
    for(int i = 19; ~i; --i) {
        bool sta = (l >> i & 1) && (!(l >> (i+1) & 1));
        if((l>>i&1) && st == -1) st = i;
        if(sta) {
            if(pv != -1) V.emplace_back(pv, i, sum), sum = 0, chk[pv] = true; 
            pv = i;
        } 
        if(l >> i & 1) sum += (1 << i);
    } 
    if(~l & 1) V.emplace_back(pv, -1, sum), chk[pv] = true;
    for(int i = st; i; --i) {
        if(chk[i]) {
            if(i != st) {
                V.emplace_back(i+1, i-1, 1<<i);
                V.emplace_back(i+1, i-1, (1<<i) | (1<<(i-1)));
            }
        } else {
            V.emplace_back(i, i-1, 1<<i);
        }
        V.emplace_back(i, i-1, 0);
    }
    for(int i = 19; i > st; --i) V.emplace_back(i, i-1, 0);
    vector<iii> ans;
    for(auto x : V) {
        int a, b, c;
        tie(a, b, c) = x;
        if(b != 0 && b != -1) ans.emplace_back(20 - a, 20 - b, c);
        else if(b == -1) ans.emplace_back(20-a, 20, c);
        else ans.emplace_back(20-a, 20, c), ans.emplace_back(20-a, 20, c+1); 
    }
    printf("%d %d\n", 20, (int)ans.size());
    for(auto x : ans) {
        int a, b, c; tie(a, b, c) = x;
        printf("%d %d %d\n", a, b, c);
    }
}
