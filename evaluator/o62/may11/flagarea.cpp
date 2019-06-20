#include <bits/stdc++.h>
using namespace std;

int n;
double sum;

int main() {
    cin >> n;
    for(int i = 1, x, y, a, b; i <= 2; ++i) {
        cin >> x >> y >> a >> b; 
        sum = ((double)a*b) / 2;
    }
    printf("%.3f\n", sum);
}
