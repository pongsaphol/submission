#include <bits/stdc++.h>
using namespace std;

int a[] = {-1, 20, 35, 50, 60, 75, 91};
string b[] = {"U", "E", "D", "C", "B", "A", "A*"};

int main() {
    int n; cin >> n;
    cout << b[upper_bound(a, a+7, n) - a - 1];
}