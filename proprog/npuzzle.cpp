#include <cstdio>

int main() {
	for(int i = 1; i <= 4; ++i) {
		for(int j = 1; j <= 4; ++j) {
			char c;
			scanf(" %c", &c);
			if(c == '.') {
				printf("%d", 4-i+4-j);
			}
		}
	}
}