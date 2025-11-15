
#include <vector>

#define int long long
using namespace std;

const int hash_mod = 1e9+7, base = 131;

int binpow(int a, int b) {
    int r = 1;
    for (; b > 0; b >>= 1, a = (int)a*a%hash_mod) 
        if (b&1) r = (int)r*a%hash_mod;
    return r;
}

// begin template //
using namespace std;
template<typename T> struct StringHash {
    vector<int> pref, inv;
    StringHash(const T& s) {
        int n = s.size();
        pref.resize(n), inv.resize(n);
        inv[n-1] = binpow(binpow(base, n-1), hash_mod-2);
        for (int j = n-2; j >= 0; j--) 
            inv[j] = (int)inv[j+1] * base % hash_mod;
        for (int j = 0, b = 1; j < n; j++, b = (int)b * base % hash_mod) {
            pref[j] = (j?pref[j-1]:0) + (int)b*((int)s[j]+2)%hash_mod;
            if (pref[j] >= hash_mod) pref[j] -= hash_mod;
        }
    }
    int query(int l, int r) const {
        int ret = pref[r] - (l?pref[l-1]:0);
        if (ret < 0) ret += hash_mod;
        return (int)ret * inv[l] % hash_mod;
    }
};
// end template //

