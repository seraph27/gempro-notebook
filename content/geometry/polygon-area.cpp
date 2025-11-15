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

// Shoelace formula: area of polygon
int polygon_area(const vector<point> &polygon) {
    int n = polygon.size();
    int area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += cross(polygon[i], polygon[j]);
    }
    return abs(area) / 2;
}

// Signed area (positive for counter-clockwise, negative for clockwise)
int signed_polygon_area(const vector<point> &polygon) {
    int n = polygon.size();
    int area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += cross(polygon[i], polygon[j]);
    }
    return area / 2;
}
// end template //

