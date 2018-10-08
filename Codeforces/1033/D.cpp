#include <bits/stdc++.h>
using namespace std;

#define long long long

long gcd(long a, long b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n; scanf("%d", &n);
    vector<long> V;
    map<long, int> M;
    set<long> devi;
    for(int i = 0; i < n; ++i) {
        long val; scanf("%lld", &val);
        double v2 = val;
        double z1 = 1.0/2, z2 = 1.0/3, z3 = 1.0/4;
        long a1 = pow(v2, z1);
        long a2 = pow(v2, z2);
        long a3 = pow(v2, z3);
        bool st = false;
        if(!st) for(long i = max(a3-5, 0ll); i <= a3+5; ++i) {
            if(i * i * i * i == val) M[i] += 4, st = true, devi.emplace(i);
        }
        if(!st) for(long i = max(a2-5, 0ll); i <= a2+5; ++i) {
            if(i * i * i == val) M[i] += 3, st = true, devi.emplace(i);
        }
        if(!st) for(long i = max(a1-5, 0ll); i <= a1+5; ++i) {
            if(i * i == val) M[i] += 2, st = true, devi.emplace(i);
        }
        if(st) continue;
        V.emplace_back(val);
    }
    for(auto x : V) for(auto y : V) if(gcd(x, y) != 1 and gcd(x, y) != x) devi.emplace(gcd(x, y));

    int cnt = 0;
    map<long, int> summ;
    for(auto &x : V) {
        for(auto z : devi) {
            if(x % z == 0) M[z]++, M[x/z]++, x = 1;
        }
        if(x != 1) summ[x]++;
    } 
    long mod = 998244353;
    long ans = 1;
    for(auto x : M) ans = (ans * (x.second+1)) % mod;
    for(auto x : summ) {
        ans = (ans * (1 + x.second) * (1 + x.second)) % mod;
    }
    printf("%lld\n", ans);
}
