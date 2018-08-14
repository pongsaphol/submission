#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pil pair<int, long>
#define x first
#define y second

const int N = 45, M = (1<<20) + 5;

int n, H[N], t[M];
long k, G[N];
vector<pil> V, V2;
vector<long> coor;
    
int get(long val) { return upper_bound(coor.begin(), coor.end(), val) - coor.begin(); }

void update(long x) {
    for(int i = get(x); i; i -= i & -i) t[i]++;
}

int query(long x) {
    int sum = 0;
    for(int i = get(x); i < M; i += i & -i) sum += t[i];
    return sum;
}

int main() {
    scanf("%d %lld", &n, &k);
    coor.emplace_back((long)(-1e18)), coor.emplace_back(0);
    int m = n >> 1;
    int z = n - m;
    long ans = 0;
    for(int i = 0; i < n; ++i) scanf("%d %lld", H+i, G+i);
    for(int i = 1; i < 1 << m; ++i) {
        long sumGold = 0;
        int last = 0;
        bool st = true;
        for(int j = 0; j < m; ++j) if(i >> j & 1) {
            if(last <= H[j]) sumGold += G[j], last = H[j];
            else { st = false; break; }
        }
        if(st) {
            V.emplace_back(last, sumGold), coor.emplace_back(sumGold);
            if(sumGold >= k) ans++;
        }    
    } 
    sort(V.begin(), V.end());
    sort(coor.begin(), coor.end());
    for(int i = 1; i < 1 << z; ++i) {
        long sumGold = 0;
        int last = 0, ft = -1;
        bool st = true;
        for(int j = 0; j < z; ++j) if(i >> j & 1) {
            if(ft == -1) ft = H[j+m];
            if(last <= H[j+m]) sumGold += G[j+m], last = H[j+m];
            else { st = false; break; }
        }
        if(st) V2.emplace_back(ft, k - sumGold);
    } 
    sort(V2.begin(), V2.end());
    update(0);
    int ptr = 0;
    for(auto x : V2) {
        while(ptr != V.size() && V[ptr].x <= x.x) update(V[ptr++].y);
        ans += query(x.y);
    }
    printf("%lld\n", ans);
}
