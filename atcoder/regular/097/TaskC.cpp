#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;

char arr[N];
vector<string> vec;

int main() {
  scanf("%s", arr);
  int n = strlen(arr);
  for(int i = 0; i < n; ++i) {
    string str;
    for(int j = i; j < n && j < i+5; ++j) {
      str.push_back(arr[j]);
      vec.emplace_back(str);
    }
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  int k; cin >> k;
  cout << vec[k-1] << endl;
}