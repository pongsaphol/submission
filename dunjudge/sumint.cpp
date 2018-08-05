#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0; cin >> n;
    while(n--) sum += *istream_iterator<int>(cin);
    cout << sum;
}