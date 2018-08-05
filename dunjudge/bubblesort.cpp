#include <bits/stdc++.h>
using namespace std;

vector<int> V;

int main() {
    int n; scanf("%d", &n);
    for(int i = 0, ret; i < n; ++i) {
        scanf("%d", &ret);
        V.emplace_back(ret);
    }
    sort(V.begin(), V.end());
    for(int x : V) {
        printf("%d", x);
        if(--n) printf(" ");
    }
}