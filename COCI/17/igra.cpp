#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;

int n, a[3], b[3];
char A[N], B[N];

bool check() {
    for(int i = 0; i <= a[0]; ++i) {
        int x = b[1] - i;
        int y = b[2] - (a[0] - i);
        if(x < 0 || y < 0) continue;
        if(x <= a[2] && y <= a[1]) return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    scanf("%s %s", B+1, A+1);
    for(int i = 1; i <= n; ++i) {
        A[i] -= 'a', B[i] -= 'a';
        a[A[i]]++, b[B[i]]++;
    }
    for(int i = 1; i <= n; ++i) {
        a[A[i]]--;
        for(int j = 0; j < 3; ++j) {
            b[j]--;
            if(A[i] != j && check()) {
                printf("%c", j+'a');
                break;
            }
            b[j]++;
        }    
    }
}
