#include <bits/stdc++.h>
using namespace std;

#define iib tuple<int, int, bool>

const int M = 1e9+7;

int n, m, k;
vector<iib> V;
int have;

int powMod(int x) {
    int ret = 1;
    int v = 2;
    for(; x; x >>= 1) {
        if(x & 1) ret = (ret * v) % M;
        v = (v * v) % M;
    }
    return ret;
}

int solve(int n) {
    sort(V.begin(), V.end(), [](const iib &a, const iib &b) { return get<0>(a) < get<0>(b); });
    int ans = 1, pv = 0, ptr = 0;
    for(;ptr != V.size();) {
        int i = get<0>(V[ptr]);
        int f = -1;
        while(ptr < V.size() and get<0>(V[ptr]) == i) {
            bool st = (get<1>(V[ptr]) & 1) == get<2>(V[ptr]);
            if(f == -1) f = st;
            if(f != st) return 0;
            ptr++;
        }
        ans = (ans * powMod(i - pv - 1)) % M;
        pv = i;
    }
    ans = (ans * powMod(n - pv)) % M;
    have++;
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0, a, b; i < k; ++i) {
        char c; scanf(" %c %d %d", &c, &a, &b);
        V.emplace_back(a, b, c == '+' ? true : false);
    }
    int ans = 0;
    ans += solve(n);
    for(auto &x : V) swap(get<0>(x), get<1>(x));
    ans += solve(m);
    if(have == 2) ans--;
    printf("%d\n", ans % M);
}