#include <bits/stdc++.h>
using namespace std;

map<string, string> M;

int main() {
    M["C"] = "D";
    M["Dm"] = "Em";
    M["Em"] = "F#m";
    M["F"] = "G";
    M["G"] = "A";
    M["Am"] = "Bm";
    string a, b, c, d;
    while(cin >> a >> b >> c >> d) {
        cout << M[a] << ' ' << M[b] << ' ' << M[c] << ' ' << M[d] << endl;
    }
}
