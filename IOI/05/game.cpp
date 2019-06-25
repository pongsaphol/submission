#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    while(true) {
        cin >> x >> y;
        if(x < y) {
            // horizontal
            int b = y - (y/2);
            for(int k = 0; ; ++k) {
                int v = (1 << k) * (x + 1) - 1;
                if(v >= b) {
                    cout << "H " << v << endl;
                    y = v;
                    break;
                }
            }
        } else {
            // vertical
            int b = x - (x/2);
            for(int k = 0; ; ++k) {
                int v = (1 << k) * (y + 1) - 1;
                if(v >= b) {
                    cout << "V " << v << endl;
                    x = v;
                    break;
                }
            }
        }
        if(x == 1 && y == 1) break;
    }
}