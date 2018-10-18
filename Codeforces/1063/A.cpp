#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 1e5+5;

int n;
char A[N];
long cnt[100];

int main() {
    scanf("%d", &n);
    scanf("%s", A);
    for(int i = 0; i < n; ++i) cnt[A[i] - 'a']++;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i]) while(cnt[i]--) printf("%c", i + 'a');
    }
}

