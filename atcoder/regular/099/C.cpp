#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    n -= k;
    printf("%d\n", (n + k - 2) / (k - 1) + 1);
}