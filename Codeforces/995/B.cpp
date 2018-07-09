#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, A[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 2*n; ++i) scanf("%d", A+i);
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        int z = A[2*i-1];
        int pos = -1;
        for(int j = 2*i; j <= 2*n; ++j) {
            if(A[j] == z) {
                pos = j;
                break;
            }
        }
        while(pos != 2*i) {
            swap(A[pos], A[pos-1]);
            pos--;
            cnt++;
        }
    }
    printf("%d\n", cnt);
}


