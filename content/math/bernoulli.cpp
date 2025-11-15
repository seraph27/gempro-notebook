

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
// Bernoulli numbers: B_n used in formula for sum of powers 1^k + 2^k + ... + n^k
vector<int> bernoulli(int n) {
    vector<int> B(n+1);
    B[0] = 1;
    for (int m = 1; m <= n; m++) {
        B[m] = 0;
        for (int k = 0; k < m; k++) {
            int comb = 1;
            for (int i = 0; i <= k; i++) {
                comb = comb * (m + 1 - i) % mod * inv(i + 1) % mod;
            }
            B[m] = (B[m] - comb * B[k]) % mod;
        }
        B[m] = (B[m] + mod) % mod;
    }
    return B;
}

// Sum of powers: 1^k + 2^k + ... + n^k mod M
int sum_of_powers(int n, int k, const vector<int> &B) {
    int res = 0;
    for (int j = 0; j <= k; j++) {
        int comb = 1;
        for (int i = 0; i <= j; i++) {
            comb = comb * (k + 1 - i) % mod * inv(i + 1) % mod;
        }
        res = (res + comb * B[j] % mod * binpow(n + 1, k + 1 - j)) % mod;
    }
    return res * inv(k + 1) % mod;
}
// end template //

