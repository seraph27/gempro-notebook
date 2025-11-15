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

int dist_sq(point a, point b) {
    point d = a - b;
    return real(d) * real(d) + imag(d) * imag(d);
}

// Rotating Calipers: finds diameter (farthest pair) of convex polygon
int rotating_calipers(const vector<point> &hull) {
    int n = hull.size();
    if (n <= 1) return 0;
    if (n == 2) return dist_sq(hull[0], hull[1]);
    
    int max_dist = 0;
    int j = 1;
    
    // For each vertex, find its antipodal point
    for (int i = 0; i < n; i++) {
        int next_i = (i + 1) % n;
        point edge = hull[next_i] - hull[i];
        
        // Advance j while it's farther from edge i->i+1
        while (true) {
            int next_j = (j + 1) % n;
            point vec_to_next = hull[next_j] - hull[i];
            point vec_to_j = hull[j] - hull[i];
            // If next_j is farther from the edge, advance
            if (cross(edge, vec_to_next) > cross(edge, vec_to_j)) {
                j = next_j;
            } else {
                break;
            }
        }
        max_dist = max(max_dist, dist_sq(hull[i], hull[j]));
    }
    
    return max_dist;
}
// end template //

