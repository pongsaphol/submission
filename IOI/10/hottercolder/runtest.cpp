#include <bits/stdc++.h>
using namespace std;


int main() {
    int val = 500;
    int cnt = 0;
    while(val) {
        cnt++;
        val *= 2;
        val /= 3;
    }
    cout << cnt << endl;
}