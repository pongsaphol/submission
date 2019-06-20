#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int n = 100;
int c;

int main() {
    cin >> c; // cost
    vector<double> vec;
    for(int i = 1; i <= n; ++i) { // divide data
        double sumcost = 0;
        for(int j = 1; j <= n; ++j) {
            double cost = 0;
            for(int z = 1; z <= n; ++z) {
                if(z == i) {
                    cost += c;
                    break;
                } else {
                    cost++;
                    if(cost == j) break;
                }
            }
            cost /= j;
            sumcost += cost;
        }
        cout << i << ' ' << sumcost << endl;
        vec.emplace_back(sumcost);
    } 
        cout << "pos => " << (min_element(vec.begin(), vec.end()) - vec.begin() + 1) << endl;
}