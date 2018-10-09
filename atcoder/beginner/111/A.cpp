#include <bits/stdc++.h>
using namespace std;

char A[6];

int main() {
    scanf("%s", A);
    for(int i = 0; i < 3; ++i) {
        if(A[i] == '1') A[i] = '9';
        else A[i] = '1';
    }
    printf("%s", A);
}
