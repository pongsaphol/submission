#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

map<int, int> M;
char A[N];

int main() {
    int T; scanf("%d", &T);
    long long sum = 0;
    while(T--) {
        scanf("%s", A);
        int num = 0;
        for(int i = 0; A[i]; ++i) num ^= (1 << (A[i] - 'a'));
        sum += M[num];
        for(int i = 0; i < 26; ++i) sum += M[num ^ (1 << i)];
        M[num]++;
    }
    printf("%lld\n", sum);
}
