#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        if(i & 1) printf("I hate ");
        else printf("I love ");
        if(i != n) printf("that ");
    }
    printf("it");
}
