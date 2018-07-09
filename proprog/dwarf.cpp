#include <cstdio>

int sum, arr[10], cache[10];
bool chk = false;

void rcsf(int lv, int p) {
	if(lv == 7) {
		if(!chk && sum == 100) {
			for(int i = 0; i < 7; ++i) {
				printf("%d\n", arr[cache[i]]);
			}
			chk = true;
		}
		return;
	}
	for(int i = p; i < 9; ++i) {
		sum += arr[i];
		cache[lv] = i;
		rcsf(lv+1, i+1);
		sum -= arr[i];
	}
}

int main() {
	for(int i = 0; i < 9; ++i)
		scanf("%d", arr+i);
	resf(0,0);
}