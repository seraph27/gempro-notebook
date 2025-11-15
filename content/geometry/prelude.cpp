#include <complex>

#define int long long
using namespace std;

using i64 = int;

// begin template //
using namespace std;
using D = i64;
using point = complex<D>;

D dot(point a, point b) {
	return real(conj(a) * b);
}
D cross(point a, point b) {
	return imag(conj(a) * b);
}
// end template //
