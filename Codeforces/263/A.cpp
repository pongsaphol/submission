#include <bits/stdc++.h>
using namespace std;

int main() {
    for(int i = 1; i <= 5; ++i) for(int j = 1; j <= 5; ++j) {
        int now; cin >> now;
        if(now) cout << abs(i-3) + abs(j-3) << endl;
    }
}
