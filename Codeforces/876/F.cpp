#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 2e5;

vector<int> bit[32];
int n, A[MAXN], t[MAXN<<1], inf = 1e9;

int query(int l, int r) {
	int mx = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l&1) mx = max(mx, t[l++]);
		if(r&1) mx = max(mx, t[--r]);
	}
	return mx;
}

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input();
	for(int i = 1; i <= n; ++i) {
		int now = input();
		for(int j = 0; j < 31; ++j) {
			if(now & (1<<j)) bit[j].emplace_back(i);
		}
		A[i] = now;
		t[i+n] = now;
	}
	long ans = 0;
	for(int i = n; i >= 1; --i) t[i] = max(t[i<<1], t[i<<1|1]);
	for(int i = 1; i <= n; ++i) {
		int low  = -1, up = inf, len = log2(A[i]);
		for(int j = 0; j < len; ++j) if(!(A[i]&(1<<j))) {
			int L = 0, R = bit[j].size()-1;
			while(L < R) {
				int mid = (L+R+1)/2;
				if(bit[j][mid] >= i) R = mid-1;
				else L = mid;
			}
			if(bit[j][L] < i && A[L] < A[i]) low = max(low, bit[j][L]);
			L = 0, R = bit[j].size()-1;
			while(L < R) {
				int mid = (L+R)/2;
				if(bit[j][mid] <= i) L = mid+1;
				else R = mid;
			}
			if(bit[j][L] > i && A[L] < A[i]) up = max(up, bit[j][L]);
		}
		if(low == -1 && up == inf) continue;
		if(low != -1) {
			int L = 1, R = low;
			while(L < R) {
				int mid = (L+R)/2;
				if(query(mid, low) <= A[i]) R = mid;
				else L = mid+1;
			}
			int mxl = low - R + 1;
			L = i, R = n;
			while(L < R) {
				int mid = (L+R+1)/2;
				if(query(i, mid) <= A[i]) L = mid;
				else R = mid-1;
			}
			int mxr = L - i + 1;
			ans += (long)mxl * mxr;
			printf("%d %lld\n",i, ans);
		}
		if(up != inf) {
			int mxl, mxr;
			if(low != -1) mxl = low+1;
			else{
				int L = 1, R = i;
				while(L < R) {
					int mid = (L+R)/2;
					if(query(mid, i) <= A[i]) R = mid;
					else L = mid+1;
				}
				mxl = i - R + 1;
			}
			int L = up, R = n;
			while(L < R) {
				int mid = (L+R+1)/2;
				if(query(up, mid) <= A[i]) L = mid;
				else R = mid-1;
			}
			mxr = L - up + 1;
			ans += (long)mxl * mxr;
		}
	}
	printf("%lld\n", ans);
}