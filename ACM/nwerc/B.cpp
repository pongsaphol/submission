#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if(n <= 3) return !printf("1");
    printf("%d\n", n-2);
}