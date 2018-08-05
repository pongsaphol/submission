#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    int sum = 0;
    for(int i = 0, ret; i < n; ++i) {
        scanf("%d", &ret);
        sum += ret;
        printf("%d\n", sum / m);
        sum %= m;
    }
}