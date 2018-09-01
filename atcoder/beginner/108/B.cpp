#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int d1 = c-a, d2 = d-b;
    swap(d1, d2), d1 *= -1;
    c += d1, d += d2;
    printf("%d %d ", c, d);
    swap(d1, d2), d1 *= -1;
    c += d1, d += d2;
    printf("%d %d ", c, d);
}
