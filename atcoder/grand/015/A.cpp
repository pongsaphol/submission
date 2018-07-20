#include <bits/stdc++.h>
#define long long long 
using namespace std;
     
int main() {
    long n, a, b; cin >> n >> a >> b;
    if(n == 1) return !printf("%d\n", a == b);
    if(a > b) return !printf("0");
    long l = a * (n - 1) + b, r = a + (n - 1) * b;
    printf("%lld\n", r-l+1);
}
