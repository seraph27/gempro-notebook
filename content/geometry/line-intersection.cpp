#include <complex>

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

// Line segment intersection
bool segments_intersect(point a, point b, point c, point d) {
    auto orient = [](point p, point q, point r) {
        return cross(q - p, r - p);
    };
    int o1 = orient(a, b, c);
    int o2 = orient(a, b, d);
    int o3 = orient(c, d, a);
    int o4 = orient(c, d, b);
    
    if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) {
        // Collinear case - check bounding boxes
        int min_x1 = min(real(a), real(b)), max_x1 = max(real(a), real(b));
        int min_y1 = min(imag(a), imag(b)), max_y1 = max(imag(a), imag(b));
        int min_x2 = min(real(c), real(d)), max_x2 = max(real(c), real(d));
        int min_y2 = min(imag(c), imag(d)), max_y2 = max(imag(c), imag(d));
        return max(min_x1, min_x2) <= min(max_x1, max_x2) &&
               max(min_y1, min_y2) <= min(max_y1, max_y2);
    }
    
    return (o1 * o2 <= 0) && (o3 * o4 <= 0);
}

// Line intersection point (assumes lines intersect, returns approximate integer point)
point line_intersection(point a, point b, point c, point d) {
    point ab = b - a, cd = d - c, ac = c - a;
    int denom = cross(ab, cd);
    if (denom == 0) return point(0, 0); // Parallel lines
    int t = cross(ac, cd);
    // Note: This uses integer division. For exact fractions, use Fraction class.
    return a + point(real(ab) * t / denom, imag(ab) * t / denom);
}
// end template //

