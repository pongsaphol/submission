#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 2e4+5;

int n;
char A[N][15];

pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
pii mul(pii a, pii b) { return pii(a.x * b.x, a.y * b.y); }
pii iden(131, 133);
pii ret[N];
map<pii, int> M;

int main() {
    scanf("%d", &n);
    for(int z = 1; z <= n; ++z) {
        scanf("%s", A[z]+1);
        int len = strlen(A[z]+1);
        set<pii> S;
        pii hash;
        for(int i = 1; i <= len; ++i) for(int j = i; j <= len; ++j) {
            if(i == j) hash = pii(0, 0); 
            hash = add(mul(hash, iden), pii(A[z][j], A[z][j]));
            S.emplace(hash); 
            if(i == 1 && j == len) ret[z] = hash;
        }
        for(auto x : S) M[x]++;
    }
    int sum = -n;
    for(int i = 1; i <= n; ++i) sum += M[ret[i]];
    return !printf("%d\n", sum);
}