#include <cstdio>
#include <algorithm>
using namespace std;

int arr[6];

int main() {
	//freopen("r", "r", stdin);
	for(int i = 1; i <= 5; ++i) {
		scanf("%d", arr + i);
	}
	while(true) {
		for(int j = 1; j <= 4; ++j) {
			if(arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				for(int j = 1; j <= 5; ++j) printf("%d ", arr[j]);
				printf("\n");
			}
		}
		bool st = true;
		for(int j = 1; j <= 5; ++j) if(arr[j] != j) st = false;
		if(st) break;
	}
}