#include <cstdio>
#include <algorithm>
using namespace std;

int arr[26];

int main(){
	//freopen("r", "r",stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	while(n--){
		char now;
		scanf(" %c", &now);
		arr[now-'a'] ++;
	}
	int mx = 0;
	for(int i = 0; i < 26; ++i) {
		mx = max(mx, arr[i]);
	}
	if(mx > m) printf("NO\n");
	else printf("YES\n");
}