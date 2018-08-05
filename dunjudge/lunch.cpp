#include <bits/stdc++.h>
using namespace std;

int a[] = {0, 3, 6, 9};
string b[] = {"That's a terrible potato!", "That's a normal potato!", "That's a good potato!", "OMG POTATOES!!!"};

int main() {
    cout << b[upper_bound(a, a+4, *istream_iterator<int>(cin)) - a - 1];
}