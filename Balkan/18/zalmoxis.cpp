#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 1e6+5;

class zalmoxis {
private:
    int n, k, sz;
    int A[2][N];
    bool state[2][N];
    vector<int> vec;
    void build(int dep, int l, int r) {
        if(l == r) return void(vec.emplace_back(dep));
        int m = l + r >>1;
        build(dep-1, l, m), build(dep-1, m+1, r);
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k;
        sz = n;
        for(int i = 0; i < sz; ++i) {
            cin >> A[0][i];
            state[0][i] = true;
        }
        for(int i = 0; i < 30; ++i) {
            int sum = 0, pos = 0;
            bool st = false;
            for(int j = 0; j < sz; ++j) {
                if(A[i&1][j] <= i) sum += 1 << A[i&1][j];
                else if(sum) {
                    assert(sum == 1 << i);
                    A[~i&1][pos] = i, state[~i&1][pos] = false, sum += 1 << i;
                    pos++;
                }
                A[~i&1][pos] = A[i&1][j], state[~i&1][pos] = state[i&1][j];
                pos++;
                if(sum == 1 << (i+1)) sum = 0;
            }
            if(sum) {
                assert(sum == 1 << i);
                A[~i&1][pos] = i, state[~i&1][pos] = false, sum += 1 << i;
                pos++;    
            }
            sz = pos;
        }
        int mx = 0, pos = 0;
        for(int j = 0; j < sz; ++j) if(!state[0][j] && mx < A[0][j]) mx = A[0][j], pos = j;
        int reach = n+k - sz + 1;
        for(int j = 0; j < sz; ++j) {
            if(j != pos) cout << A[0][j] << ' ';
            else {
                build(A[0][j], 1, reach);
                for(auto x : vec) cout << x << ' '; 
            }
        }
        cout << endl;
//        for(int j = 0; j < sz; ++j) cerr << A[0][j] << ' ';
//        cerr << endl;
//        for(int j = 0; j < sz; ++j) cerr << state[0][j] << "  ";
//        cerr << endl;
    }
};