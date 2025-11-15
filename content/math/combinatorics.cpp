
#include <vector>

using namespace std;

const int mod = 1e9+7;

int binpow(int a, int b) {
    int r = 1;
    for (; b; a = a*a%mod, b >>= 1) 
        if (b & 1) r = r*a%mod;
    return r;
}

int inv(int x) {
    return binpow(x, mod - 2);
}

// begin template //
using namespace std;
vector<int> facs, invfacs;

int choose(int n, int k) {
    if (k > n || n < 0 || k < 0) return 0;
    return facs[n] * invfacs[k] % mod * invfacs[n-k] % mod;
}

void finit(int nx) {
    facs.resize(nx+1);
    invfacs.resize(nx+1);
    facs[0] = facs[1] = invfacs[0] = invfacs[1] = 1;
    for (int i = 2; i <= nx; i++) {
        facs[i] = facs[i-1] * i % mod;
    }
    invfacs[nx] = inv(facs[nx]);
    for (int i = nx-1; i > 1; i--) {
        invfacs[i] = invfacs[i+1] * (i+1) % mod;
    }
}
// end template //

