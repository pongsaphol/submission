#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main() {
    scanf("%d", &n);
    for(int i = 0, val; i < n; ++i) {
        scanf("%d", &val);
        while(~val & 1) val >>= 1, cnt++;
    }
    printf("%d\n", cnt);
}