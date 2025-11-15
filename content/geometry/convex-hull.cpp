#include <algorithm>
#include <complex>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
using point = complex<int>;
int cross(point a, point b) {
    return imag(conj(a) * b);
}

int dot(point a, point b) {
    return real(conj(a) * b);
}

// Andrew's monotone chain algorithm
vector<point> convex_hull(vector<point> points) {
    int n = points.size();
    if (n <= 1) return points;
    
    sort(points.begin(), points.end(), [](point a, point b) {
        return real(a) < real(b) || (real(a) == real(b) && imag(a) < imag(b));
    });
    
    vector<point> hull;
    hull.reserve(n + 1);
    
    // Lower hull
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && 
               cross(hull.back() - hull[hull.size() - 2], points[i] - hull.back()) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    // Upper hull
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while ((int)hull.size() > lower_size && 
               cross(hull.back() - hull[hull.size() - 2], points[i] - hull.back()) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    // Remove duplicate last point
    if (hull.size() > 1) hull.pop_back();
    return hull;
}
// end template //

