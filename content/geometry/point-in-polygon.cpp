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

// Point in polygon: ray casting algorithm
// Returns: 0 = outside, 1 = on boundary, 2 = inside
int point_in_polygon(point p, const vector<point> &polygon) {
    int n = polygon.size();
    int cnt = 0;
    bool on_edge = false;
    
    for (int i = 0; i < n; i++) {
        point a = polygon[i];
        point b = polygon[(i + 1) % n];
        
        // Check if point is on edge (collinear and within segment)
        if (cross(b - a, p - a) == 0) {
            int min_x = min(real(a), real(b));
            int max_x = max(real(a), real(b));
            int min_y = min(imag(a), imag(b));
            int max_y = max(imag(a), imag(b));
            // Check if p is on the line segment ab
            if (real(p) >= min_x && real(p) <= max_x &&
                imag(p) >= min_y && imag(p) <= max_y) {
                on_edge = true;
            }
        }
        
        // Ray casting: count intersections with horizontal ray
        if ((imag(a) > imag(p)) != (imag(b) > imag(p))) {
            int x_intersect = real(a) + (imag(p) - imag(a)) * (real(b) - real(a)) / (imag(b) - imag(a));
            if (real(p) < x_intersect) {
                cnt++;
            }
        }
    }
    
    if (on_edge) return 1;
    return (cnt % 2 == 1) ? 2 : 0;
}
// end template //

