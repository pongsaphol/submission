#include <bits/stdc++.h>
using namespace std;

int brute_force(int x) {
    map<int, vector<int> > M;
    int cnt = 0;
    map<int, int> S;
    int rcnt = 0;
    for(int i = 0; i <= x; ++i) for(int j = 0; j <= x; ++j) for(int k = 0; k <= x; ++k) for(int l = 0; l <= x; ++l) {
        if(i + j + k + l != x) continue;
        vector<int> V;
        V.emplace_back(i), V.emplace_back(j), V.emplace_back(k), V.emplace_back(l);
        int val = i + j * 5 + k * 10 + l * 50;
        if(M[val].empty()) M[val] = V, rcnt++;
        else {
            cnt++;
            int len = 0;
            for(int i = 0; i < 4; ++i) len += M[val][i] + V[i] - 2 * min(M[val][i], V[i]);
            S[len >> 1]++;            
            
        } 
    }
    return rcnt;
}

int A[12] = {0, 4, 6, 10, 15, 21, 27, 33, 39, 43, 46, 48};
int main() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= 11; ++i) A[i] += A[i-1];
    if(n <= 11) return !printf("%d\n", A[n]);
    else printf("%lld\n", A[11] + 49ll * (n - 11));
}

// int main() {
//     for(int i = 1; i <= 70; ++i) printf("%d %d\n", i, brute_force(i)); 
//     for(int i = 2; i <= 70; ++i) printf("%d %d\n", i, brute_force(i) - brute_force(i-1));
// }