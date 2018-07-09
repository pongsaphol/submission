#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> V;
    int n; cin >> n;
    while(n--) {
        int x; cin >> x; V.emplace_back(x);
    }
    int cnt = 0;
    for(int i = 1; i < V.size()-1; ++i) {
        if(V[i] > V[i-1] and V[i] > V[i+1]) cnt++;
        if(V[i] < V[i-1] and V[i] < V[i+1]) cnt++;
    }
    cout << cnt << endl;
}