#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("out.txt", "w", stdout);
    int N = 100;
    int inf = 1e9;
    printf("%d %d %d\n", N, inf, inf);
    for(int i = 1; i <= N; ++i) printf("%d", i & 1); 
}