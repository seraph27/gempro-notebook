#include <algorithm>
#include <complex>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
using point = complex<int>;

int dist_sq(point a, point b) {
    point d = a - b;
    return real(d) * real(d) + imag(d) * imag(d);
}

// Closest pair of points using divide and conquer
pair<point, point> closest_pair(vector<point> points) {
    int n = points.size();
    if (n <= 1) return {points[0], points[0]};
    
    sort(points.begin(), points.end(), [](point a, point b) {
        return real(a) < real(b) || (real(a) == real(b) && imag(a) < imag(b));
    });
    
    function<pair<point, point>(int, int)> solve = [&](int l, int r) -> pair<point, point> {
        if (r - l <= 3) {
            int min_dist = LLONG_MAX;
            pair<point, point> best;
            for (int i = l; i < r; i++) {
                for (int j = i + 1; j < r; j++) {
                    int d = dist_sq(points[i], points[j]);
                    if (d < min_dist) {
                        min_dist = d;
                        best = {points[i], points[j]};
                    }
                }
            }
            return best;
        }
        
        int mid = (l + r) / 2;
        auto left = solve(l, mid);
        auto right = solve(mid, r);
        
        int d_left = dist_sq(left.first, left.second);
        int d_right = dist_sq(right.first, right.second);
        int d = min(d_left, d_right);
        auto best = (d_left < d_right) ? left : right;
        
        int mid_x = real(points[mid]);
        vector<point> strip;
        for (int i = l; i < r; i++) {
            int dx = real(points[i]) - mid_x;
            if (dx * dx < d) {
                strip.push_back(points[i]);
            }
        }
        
        sort(strip.begin(), strip.end(), [](point a, point b) {
            return imag(a) < imag(b);
        });
        
        for (int i = 0; i < (int)strip.size(); i++) {
            for (int j = i + 1; j < (int)strip.size() && (imag(strip[j]) - imag(strip[i])) * (imag(strip[j]) - imag(strip[i])) < d; j++) {
                int d_strip = dist_sq(strip[i], strip[j]);
                if (d_strip < d) {
                    d = d_strip;
                    best = {strip[i], strip[j]};
                }
            }
        }
        
        return best;
    };
    
    return solve(0, n);
}
// end template //

