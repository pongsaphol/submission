#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 2e4+5;

int n, m;
int X[N], Y[N];
int pos[N], t[N];

void update(int x) {
    if(x <= n) t[x]++, update(x + (x & -x));
}

int query(int x) {
    return t[x] + (x ? query(x - (x & -x)) : 0);
}

int main() {
    scanf("%d %d", &n, &m);
    vector<int> coorx, coory;
    coorx.reserve(n), coory.reserve(n); 
    for(int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", X+i, Y+i);
        pos[i] = i;
        coorx.emplace_back(X[i]), coory.emplace_back(Y[i]); 
    }
    sort(all(coorx)), sort(all(coory));
    for(int i = 0; i < n; ++i) {
        X[i] = upper_bound(all(coorx), X[i]) - coorx.begin();
        Y[i] = upper_bound(all(coory), Y[i]) - coory.begin();
    }
    sort(pos, pos+n, [&](const int &a, const int &b) { return X[a] < X[b]; });
    int mn = 1e9;
    int a1, a2;
    for(int i = 0; i < n; ++i) {
        memset(t, 0, sizeof t);
        update(Y[pos[i]]);
        for(int j = i+1; j < n; ++j) {
            update(Y[pos[j]]);
            int val;
            if(Y[pos[j]] > Y[pos[i]]) val = query(Y[pos[j]]) - query(Y[pos[i]] - 1);
            else val = query(Y[pos[i]]) - query(Y[pos[j]] - 1);
            if(val < mn && val >= m) mn = val, a1 = pos[i], a2 = pos[j];
            if(mn == m) break;
        }
        if(mn == m) break;
    }
    printf("%d %d\n", a1+1, a2+1);
}