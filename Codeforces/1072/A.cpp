#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    int sum = 0;
    for(int i = 0; i < k; ++i) {
        sum += (n+m-2) * 2;
        n -= 4, m -= 4;
    }
    printf("%d\n", sum);
}
