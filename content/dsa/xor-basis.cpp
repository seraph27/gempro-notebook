#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
struct XorBasis {
    vector<int> basis;
    static const int BITS = 60;
    
    XorBasis() : basis(BITS, 0) {}
    
    void insert(int x) {
        for (int i = BITS - 1; i >= 0; i--) {
            if (!(x >> i)) continue;
            if (!basis[i]) {
                basis[i] = x;
                return;
            }
            x ^= basis[i];
        }
    }
    
    bool can_form(int x) {
        for (int i = BITS - 1; i >= 0; i--) {
            if (x >> i) {
                if (!basis[i]) return false;
                x ^= basis[i];
            }
        }
        return true;
    }
    
    int max_xor() {
        int res = 0;
        for (int i = BITS - 1; i >= 0; i--) {
            if (basis[i] && !(res >> i)) {
                res ^= basis[i];
            }
        }
        return res;
    }
    
    int min_xor(int x) {
        int res = x;
        for (int i = BITS - 1; i >= 0; i--) {
            if (basis[i] && (res >> i)) {
                res ^= basis[i];
            }
        }
        return res;
    }
    
    int size() {
        int cnt = 0;
        for (int i = 0; i < BITS; i++) {
            if (basis[i]) cnt++;
        }
        return cnt;
    }
};
// end template //

