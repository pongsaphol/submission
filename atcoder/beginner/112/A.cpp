#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    if(n == 1) puts("Hello World");
    else {
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
}
