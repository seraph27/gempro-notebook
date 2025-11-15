

#include <vector>

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
vector<int> catalan;

void init_catalan(int n) {
    catalan.resize(n+1);
    catalan[0] = 1;
    for (int i = 1; i <= n; i++) {
        catalan[i] = catalan[i-1] * (4*i - 2) % mod * inv(i + 1) % mod;
    }
}

int catalan_number(int n) {
    return catalan[n];
}
// end template //

