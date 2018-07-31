#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b;

int main() {
    cin >> n;
    a.resize(n), b.resize(n);
    for_each(a.begin(), a.end(), [](int &x) { cin >> x; });
    for_each(b.begin(), b.end(), [](int &x) { cin >> x; });
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    bool st = true;
    for(int i = 0; i < n; ++i) st &= (a[i] <= b[i]);
    puts(st ? "DA" : "NE");
}