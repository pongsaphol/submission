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

const int N = 2e5+5;

class safety {
private:
    int n;
    long k, high, now;
    multiset<long> Sl, Sr;
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k;
        for(int i = 0; i < n; ++i) {
            cin >> now;
            high += now;
            Sl.emplace(now + i*k), Sr.emplace(now - i*k);
            while(*Sl.rbegin() - i*k > *Sr.begin() + i*k) {
                long a = *Sl.rbegin(), b = *Sr.begin();
                Sl.erase(Sl.find(*Sl.rbegin())), Sr.erase(Sr.find(*Sr.begin()));
                Sl.emplace(b + 2*i*k), Sr.emplace(a - 2*i*k);
            } 
            long pv = 0;
            while(!Sl.empty() && *Sl.begin() - i*k <= k) {
                high -= Sl.size() * (*Sl.begin() - i*k - pv);
                pv = *Sl.begin() - i*k;
                Sl.erase(Sl.begin());
            }
            high -= Sl.size() * (k - pv);
        }
        long pv = 0, ptr = Sl.size();
        for(auto x : Sl) {
            high -= ptr-- * (x - n*k - pv);
            pv = x - n*k;
        }
        cout << high << endl;
    }
};