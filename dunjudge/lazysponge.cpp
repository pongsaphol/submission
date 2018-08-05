#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0, ret; i < n; ++i) {
        scanf("%d", &ret);
        if(i == m-1) return !printf("%d\n", ret);
    }
}