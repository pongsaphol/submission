#include <bits/stdc++.h>
using namespace std;

vector<int> V = {0, 40, 45, 50, 55, 60, 65, 70, 80};
float a[] = {0.8, 1.2, 1.6, 2.0, 2.4, 2.8, 3.2, 3.6, 4.0};

int main() {
    printf("%.1f", a[upper_bound(V.begin(), V.end(), *istream_iterator<int>(cin)) - V.begin() - 1]);
}