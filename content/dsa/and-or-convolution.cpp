#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
// AND convolution: c[i] = sum_{j & k = i} a[j] * b[k]
void fwht_and(vector<int>& a, bool inv) {
    int n = a.size();
    for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int u = a[i + j], v = a[i + j + len];
                if (!inv) {
                    a[i + j] = u + v;
                    a[i + j + len] = v;
                } else {
                    a[i + j] = u - v;
                    a[i + j + len] = v;
                }
            }
        }
    }
}

// OR convolution: c[i] = sum_{j | k = i} a[j] * b[k]
void fwht_or(vector<int>& a, bool inv) {
    int n = a.size();
    for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int u = a[i + j], v = a[i + j + len];
                if (!inv) {
                    a[i + j] = u;
                    a[i + j + len] = u + v;
                } else {
                    a[i + j] = u;
                    a[i + j + len] = v - u;
                }
            }
        }
    }
}
// end template //

