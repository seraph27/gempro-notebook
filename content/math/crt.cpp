
#include <array>
#include <vector>

#define int long long
using namespace std;
#define ar array

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

array<int, 2> extgcd(int a, int b) {
    if (b == 0) return {1, 0};
    auto [y, x] = extgcd(b, a % b);
    return {x, y - (a / b) * x};
}

// begin template //
using namespace std;
// Chinese Remainder Theorem: solves x = a_i (mod m_i) for all i
// Returns {x, M} where x is solution modulo M = lcm(m_i), or {-1, -1} if no solution
array<int, 2> crt(const vector<int> &a, const vector<int> &m) {
    int x = a[0], M = m[0];
    for (int i = 1; i < (int)a.size(); i++) {
        int a2 = a[i], m2 = m[i];
        int g = gcd(M, m2);
        if ((a2 - x) % g != 0) return {-1, -1};
        int m1 = M / g, m2g = m2 / g;
        auto [k1, k2] = extgcd(m1, m2g);
        k1 = (k1 % m2g + m2g) % m2g;
        int lcm = M * m2g;
        x = (x + (a2 - x) / g % m2g * k1 % m2g * M) % lcm;
        x = (x + lcm) % lcm;
        M = lcm;
    }
    return {x, M};
}
// end template //

