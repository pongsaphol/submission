#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for(int i = 0; i <= 30; ++i) for(int j = 0; j <= 30; ++j) 
        if(i * 4 + j * 7 == n) return !printf("Yes");
    puts("No");
}