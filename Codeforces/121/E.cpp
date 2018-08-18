#include <bits/stdc++.h>
using namespace std;

#define iiii tuple<int, int, int, int>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

const int N = 1e5+5;

int n, m, A[N], t[N];
bool luc[N];
vector<int> lucky;

void update(int x, int v) {
    for(; x <= n; x += x&-x) t[x] += v;
}

int query(int x) {
    int v = 0;
    for(; x; x -= x&-x) v += t[x];
    return v;
}

void genLucky() {
    for(int len = 1; len <= 4; ++len) {
        char A[len+5] = {};
        for(int j = 0; j < (1<<len); ++j) {
            for(int k = 0; k < len; ++k) 
                A[k] = (j >> k & 1) ? '4' : '7';
            int now; sscanf(A, "%d", &now);
            lucky.emplace_back(now);
        }
    }
}

int main() {
    genLucky(); 
    for(auto x : lucky) luc[x] = true;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i), update(i, luc[A[i]]);
    for(int i = 0, a, b, c; i < m; ++i) {
        char inp[9]; scanf("%s %d %d", inp, &a, &b);
        if(inp[0] == 'c') printf("%d\n", query(b) - query(a-1));
        else {
            scanf("%d", &c);
            for(; a <= b; ++a) {
                int z = luc[A[a]+c];
                z -= luc[A[a]]; A[a] += c;
                if(z) update(a, z);
            }
        }
    }
}