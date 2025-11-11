#include <complex>

using namespace std;

using i64 = long long;

// begin template //
using D = i64;
using point = complex<D>;

D dot(point a, point b) {
	return real(conj(a) * b);
}
D cross(point a, point b) {
	return imag(conj(a) * b);
}
// end template //
