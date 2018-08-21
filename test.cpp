#include <bits/stdc++.h>
using namespace std;

#define C 1000

const int N = 20;
bool st[N];
int c[N];

int main() {
    srand(time(NULL));
    for(int i = 0; i < N; ++i) st[i] = rand() & 1;
    for(int k = 0;; ++k) {
        for(int i = 0; i < N; ++i) {
            if(st[i] == (rand() & 1)) {
                if(i == 15) return !printf("%d\n", k);
                break;
            }
        }
    } 
    for(int i = 0; i < N; ++i) printf("%d %d\n", i, c[i]);
}