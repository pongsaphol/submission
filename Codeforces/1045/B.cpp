#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;

int n, m;
int A[N];

int main() {
    set<int> bad;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%d", A+i);
    sort(A, A+n);
    bool st = false;
    bool now = true;
    if(m <= 500000) for(int i = 0; 2 * i < m; ++i) if(A[i] != 2*i) now = false;
    st |= now;
    now = true;
    if(m <= 500000) for(int i = 0; 2*i + 1 < m; ++i) if(A[i] != 2*i + 1) now = false;
    st |= now;
    if(m > 500000) st = false;
    if(st) {
        vector<int> V;
        if(m & 1) V.emplace_back(m-1);
        else for(int i = 0; i < m; i += 2) V.emplace_back(i);
        printf("%d\n", (int)V.size());
        for(auto x : V) printf("%d ", x);
        return 0;
    }
    if(n*2 > m) {
        vector<int> ret;
        for(int i = 0, p = 0; i < m; ++i) {
            if(A[p] != i) ret.emplace_back(i);
            else p++;
        }
        assert((int)ret.size() + n == m);
        n = ret.size();
        for(int i = 0; i < n; ++i) A[i] = ret[i];
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (A, A+n, std::default_random_engine(seed));
    set<int> b2;
    for(int i = 0; i < n; ++i) bad.emplace((A[0] + A[i]) % m), b2.emplace(A[i]);
    for(int i = 1; i < n; ++i) {
        auto it = bad.begin();
        for(; it != bad.end();) {
            if(b2.find((*it - A[i] + m) % m) == b2.end()) {
                auto ret = it; ret++;
                bad.erase(it);
                it = ret;
            } else it++;
        }
    }
    printf("%d\n", (int)bad.size());
    for(auto x : bad) printf("%d ", x);
}
