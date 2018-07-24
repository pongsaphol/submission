#include <bits/stdc++.h>
using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    for(int i = 1; i <= 105; ++i) {
        if(a == b) return !printf("Yes");
        char ret = a.back(); a.pop_back();
        a = ret + a;
    }
    puts("No");
}