#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <cstring>
#include <iterator>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

char A[115], name[5][10] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
int cnt;
int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
	scanf("%s", A);
	int len = strlen(A);
	for(int i = 0; i < len; ++i) {
		for(int j = 0; j < 5; ++j) {
			bool st = true;
			int Ilen = strlen(name[j]);
			for(int k = 0; k < Ilen; ++k) {
				if(A[i+k] != name[j][k]) st = false;
			}
			if(st) cnt++;
		}
	}	
	if(cnt == 1) return !printf("YES\n");
	return !printf("NO\n");
}