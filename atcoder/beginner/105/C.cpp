#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    stack<int> s;
    if(n == 0) s.emplace(0);
    while(n != 0) {
        int r = n % -2;
        n /= -2;
        if(r < 0) {
            r += 2;
            n++;
        }
        s.emplace(r); 
    }
    while(!s.empty()) printf("%d", s.top()), s.pop();
}