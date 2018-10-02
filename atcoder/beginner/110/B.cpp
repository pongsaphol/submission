#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define input() *istream_iterator<int>(cin)

int n, m;
vector<int> A, B;

int main() {
    scanf("%d %d", &n, &m);
    A.emplace_back(input());
    B.emplace_back(input());
    for(int i = 0; i < n; ++i) A.emplace_back(input());
    for(int i = 0; i < m; ++i) B.emplace_back(input());
    puts(*max_element(all(A)) >= * min_element(all(B)) ? "War" : "No War");
}
