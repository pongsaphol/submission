#include <bits/stdc++.h>
using namespace std;

char A[6];

int main() {
    scanf("%s", A);
    int val = 0;
    for(int i = 0; i < 4; ++i) val += A[i] == '+' ? 1 : -1;
    printf("%d\n", val);
}