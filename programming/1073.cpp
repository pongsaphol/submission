#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int l, t, m;
int d[N][2], pos[N<<1];

int main() {
    scanf("%d %d", &l, &t); 
    for(int i = 1; i <= l; ++i) d[i][0] = i, pos[i] = i;
    for(int i = l; i; --i) d[i][1] = l+l-i, pos[l+l-i] = i;
    l <<= 1;
    t %= l;
    vector<int> V;
    scanf("%d", &m);
    while(m--) {
        int val; char z;
        scanf("%d %c", &val, &z);
        V.emplace_back(pos[(d[val][z=='L'] + t) % l]);
    }
    sort(V.begin(), V.end());
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
}