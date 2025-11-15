#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
// XOR convolution: c[i] = sum_{j ^ k = i} a[j] * b[k]
void fwht(vector<int>& a, bool inv) {
    int w = 32 - __builtin_clz(a.size() - 1);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < 1 << w; j += 1 << (i+1)) {
            for (int k = 0; k < 1 << i; k++) {
                auto l = a[j+k], r = a[(j+k) ^ 1 << i];
                a[j+k] = (l + r) >> inv;
                a[(j+k) ^ 1 << i] = (l - r) >> inv;
            }
        }
    }
}
// end template //

