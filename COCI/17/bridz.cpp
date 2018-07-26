#include <bits/stdc++.h>
using namespace std;

int sum = 0;
char inp[105], A[] = "XJQKA";
int c[256];

int main() {
    for(int i = 0; i < 5; ++i) c[A[i]] = i;
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s", inp);
        for(int i = 0; i < 13; ++i) sum += c[inp[i]];
    }
    printf("%d\n", sum);
}