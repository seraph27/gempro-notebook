
#include <algorithm>
#include <vector>

#define int long long
using namespace std;

const int mod = 998244353, g = 3;

int binpow(int a, int b) {
    int r = 1;
    for (; b; a = a*a%mod, b >>= 1) 
        if (b & 1) r = r*a%mod;
    return r;
}

// begin template //
using namespace std;
void butterfly(vector<int>& a, bool inv) {
    int n = a.size();
    int N = 1;
    while (N < n) N <<= 1;
    a.resize(N);
    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        r[i] = (i & 1) * (N >> 1) + (r[i >> 1] >> 1);
        if (i < r[i]) swap(a[i], a[r[i]]);
    }
    for (int i = 2; i <= N; i <<= 1) {
        int t = i >> 1, pw = binpow(g, inv ? mod - 1 - (mod - 1) / i : (mod - 1) / i);
        for (int j = 0; j < N; j += i) {
            for (int k = j, c = 1; k < j + t; k++, c = (int)c * pw % mod) {
                int u = a[k], v = (int)a[k+t] * c % mod;
                a[k] = u + v;
                a[k+t] = u - v;
                if (a[k] >= mod) a[k] -= mod;
                if (a[k+t] < 0) a[k+t] += mod;
            }
        }
    }
    if (inv) {
        int ch = binpow(N, mod - 2);
        for (int &x : a) x = (int)x * ch % mod;
    }
}
// end template //

