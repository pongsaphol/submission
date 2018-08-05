#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    do {
        printf("%d ", n);
        if(n & 1) n = 3*n+1;
        else n >>= 1;
    } while(n != 1);
    puts("1");
}