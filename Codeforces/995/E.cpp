#include <bits/stdc++.h>
using namespace std;

int main() {
    for(int i = 1; i <= 10; ++i) {
        for(int j = 1; j <= 10; ++j) {
            if((i * j) % 11 == 0) printf("%d %d\n", i, j);
        }
    }
}