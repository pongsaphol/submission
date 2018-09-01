#include <bits/stdc++.h>
using namespace std;
int a[2];

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) a[i%2]++;
    printf("%d\n", a[0] * a[1]);
}
