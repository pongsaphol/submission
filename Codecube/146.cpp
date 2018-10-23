#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
const int N = 210;
const double EPS = 1e-6;
double score[ N ];
int idx[ N ];
int n, m, k;
bool cmpScore( int u, int v ) {
return score[ u ] > score[ v ];
}
int main( void ) {
double offset = 0.0;
// read input
cin >> n >> m >> k;
for ( int i = 0 ; i < m ; ++i ) {
int u, v;
double a, b;
cin >> u >> v >> a >> b;
// update score
score[ u ] += ( a + b ) / 4;
score[ v ] += ( a + b ) / 4;
offset += ( a - b );
}
for ( int i = 1 ; i <= n ; ++i ) {
idx[ i ] = i;
}
// sort the indices into non-decreasing order
sort( idx + 1, idx + n+1, cmpScore );
// check for edge case
if ( abs( offset ) > EPS or ( n % 2 == 1 and abs( score[ idx[ n ] ] ) > EPS ) ) {
cout << -1 << endl;
return 0;
}
vector< vector< double > > ans;
int v = -1;
for ( int u = 2 ; u <= n ; u += 2 ) {
if ( score[ idx[u-1] ] > score[ idx[u] ] ) {
if ( v == -1 ) {
v = u;
} else {
double edge_weight = min( score[ idx[u-1] ] - score[ idx[u]

], score[ idx[v-1] ] - score[ idx[v] ] );

ans.push_back( { (double) idx[u], (double) idx[v], 2 * edge_weight } );

score[ idx[u] ] += edge_weight;
score[ idx[v] ] += edge_weight;
if ( abs( score[ idx[u-1] ] - score[ idx[u] ] ) > EPS ) {
v = u;
} else if ( abs( score[ idx[v-1] ] - score[ idx[v] ] ) < EPS

) {

v = -1;
}
}
}
}
if ( v != -1 and score[ idx[v-1] ] > score[ idx[v] ] ) {
double edge_weight = ( score[ idx[v-1] ] - score[ idx[v] ] );
ans.push_back( { (double) idx[v], (double) idx[v], edge_weight } );
}
// output answer
cout << setprecision(2) << fixed;
cout << ans.size() << "\n";
for ( vector<double>& data : ans ) {
cout << (int)data[0] << " " << (int)data[1] << " " << data[2] << "\n";
}
return 0;
}
