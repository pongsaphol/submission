#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pii pair<int, int>
#define x first
#define y second
#define iiii tuple<int, int, int, int>

int n;
struct Point 
{ 
    int x; 
    int y; 
}; 
  
// Given three colinear points p, q, r, the function checks if 
// point q lies on line segment 'pr' 
bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Point p, Point q, Point r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 

int main() {
    scanf("%d", &n);
    vector<iiii> V;
    long sum = 0;
    for(int i = 0, a, b, c, d; i < n; ++i) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        V.emplace_back(a, b, c, d);
        int y = abs(b - d), x = abs(a - c);
        if(y == 0 || x == 0) {
            if(y == 0) swap(x, y);
            sum += y+1;
        } else {
            int gcd = __gcd(x, y);
            y /= gcd, x /= gcd;
            sum += abs(a-c) / x + 1;
        }
    }
    set<pair<long, long> > S;
    for(int i = 0; i < n; ++i) for(int j = i+1; j < n; ++j) {
        int a, b, c, d, w, x, y, z; tie(a, b, c, d) = V[i], tie(w, x, y, z) = V[j];
        if(!doIntersect({a, b}, {c, d}, {w, x}, {y, z})) continue;
        long a1 = d - b;
        long b1 = a - c;
        long c1 = a1 * a + b1 * b;

        long a2 = z - x;
        long b2 = w - y;
        long c2 = a2 * w - b2 * x;
        long det = a1 * b2 - a2 * b1;
        if(det == 0) continue;
        long xx = b2*c1 - b1*c2;
        long yy = a1*c2 - a2*c1;

        if(xx % det != 0 || yy % det != 0) continue;
        printf("%lld %lld %lld\n", xx, yy, det);
        S.emplace(xx / det, yy / det);
        printf("%d %d\n", i, j);
    }
    printf("%d\n", (int)S.size());
    printf("%lld\n", sum - (long)S.size());
}
