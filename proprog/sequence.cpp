#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define long long long
using namespace std;

const int MOD = 2553;
typedef struct mat {
	int A[4][4];
	friend inline mat operator*(const mat &a, const mat &b) {
		mat ret;
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 4; ++j) {
				int sum = 0;
				for(int k = 0; k < 4; ++k) {
					sum += a.A[i][k] * b.A[k][j];
					sum %= MOD;
				}
				ret.A[i][j] = sum;
			}
		}
		return ret;
	}
}mat;

mat st, dp[63];
int arr[10];

void read() {
	for(int i = 1; i <= 8; ++i) scanf("%d", arr+i);
}

void build() {
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			st.A[i][j] = 0;
		}
	}
	for(int i = 0; i < 3; ++i) {
		st.A[i][i+1] = 1;
	}
	for(int i = 8; i > 4; --i) {
		st.A[3][8-i] = arr[i];
	}
	/* end build matrix */
	dp[0] = st;
	for(int i = 1; i <= 60; ++i) {
		dp[i] = dp[i-1]*dp[i-1];
	}
}

mat get(long x) {
	mat ret;
	bool st = true;
	for(int i = 60; i >= 0; --i) {
		if(x&(1ll<<i)) {
			if(st){
				st = false;
				ret = dp[i];
			}else ret = ret * dp[i];
		}
	}
	return ret;
}

int solve() {
	long in;
	scanf("%lld", &in);
	if(in <= 4) return arr[in];
	mat now = get(in-1);
	int ret = 0;
	for(int i = 1; i <= 4; ++i) {
		ret += now.A[0][i-1] * arr[i];
		ret %= MOD;
	}
	return ret;
}

int main() {
	// freopen("r", "r", stdin);
	read();
	build();
	int T;
	scanf("%d", &T);
	while(T--) printf("%d\n", solve());
}