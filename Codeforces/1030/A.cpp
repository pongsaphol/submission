#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int st = false;
    for(int i = 0, val; i < n; ++i) cin >> val, st |= val;
    puts(!st ? "EASY" : "HARD");
}
