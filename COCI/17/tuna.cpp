#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, sum = 0; cin >> n >> m;
    while(n--) {
        int a, b; cin >> a >> b;
        if(a < b) swap(a, b);
        if(a - b <= m) sum += a;
        else sum += *istream_iterator<int>(cin);
    }
    printf("%d\n", sum);
}