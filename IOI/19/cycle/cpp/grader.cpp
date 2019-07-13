#include "cycle.h"
#include <cstdio>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

static const int cnt_lim = 35;
static int n, p, cnt;

static void wrong_answer(string reason) {
	printf("%s\n", reason.c_str());
	exit(0);
}

bool jump(int x) {
	if(x < 0 || x >= n) wrong_answer("Invalid argument."), printf("-> %d %d\n", n, p);
	cnt++;
	if(cnt > cnt_lim) wrong_answer("Too many queries.");

	p = (p + x) % n;
	return (n - p) % n <= n / 2;
}

int main() {
	// for(int i = 3; i <= 30; ++i) {
	// 	n = i;
	// 	for(int j = 0; j < i; ++j) {
	// 		p = j;
	// 		escape(i);
	// 		if(p != 0) printf("%d %d\n", i, j);
	// 		cnt = 0;
	// 	}
	// }
	// return 0;
	assert(1 == scanf("%d", &n));
	assert(1 == scanf("%d", &p));

	cnt = 0;
	escape(n);

	if(p != 0) wrong_answer("The exit was not found.");
	printf("OK\n");
	fprintf(stderr, "%d\n", cnt);
	return 0;
}
