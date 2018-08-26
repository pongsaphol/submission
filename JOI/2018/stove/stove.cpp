#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    vector<int> V;
    int pv; scanf("%d", &pv);
    for(int i = 1, a; i < n; ++i) {
        scanf("%d", &a);
        V.emplace_back(a - pv - 1);
        pv = a;
    }
    sort(V.begin(), V.end());
    int v = n-k;
    for(int i = 0; i < v; ++i) n += V[i];
    printf("%d\n", n);
}