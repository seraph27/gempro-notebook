
#include <array>

#define int long long
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// begin template //
using namespace std;
array<int, 2> extgcd(int a, int b) {
    if (b == 0) return {1, 0};
    auto [y, x] = extgcd(b, a % b);
    return {x, y - (a / b) * x};
}
int topos(int x, int m) {
    x %= m; 
    if (x < 0) x += m; 
    return x;
}
int min_rem(int n, int m, int a, int b) {
    a = topos(a, m), b = topos(b, m);
    for (int g = gcd(a, m); g > 1;) 
        return g * min_rem(n, m / g, a / g, b / g) + (b % g);
    for (int nn, nm, na, nb; a; n = nn, m = nm, a = na, b = nb) {
        if (a <= m - a) {
            nn = (a * (n - 1) + b) / m;
            if (!nn) break;
            nn += (b < a);
            nm = a, na = topos(-m, a);
            nb = b < a ? b : topos(b - m, a);
        } else {
            int lst = b - (n - 1) * (m - a);
            if (lst >= 0) {b = lst; break;}
            nn = -(lst / m) + (lst % m < -a) + 1;
            nm = m - a, na = m % (m - a), nb = b % (m - a);
        }
    }
    return b;
}
array<int, 2> min_rem_pos(int n, int m, int a, int b) {
    a = topos(a, m), b = topos(b, m);
    int mn = min_rem(n, m, a, b), g = gcd(a, m);
    int x = (extgcd(a, m)[0] + m) * ((mn - b + m) / g) % (m / g);
    return {mn, x};
}
// end template //

