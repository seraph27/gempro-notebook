
#include <array>
#include <chrono>
#include <random>
#include <vector>

#define int long long
using namespace std;

const int hash_mod = 1e9+7;

int binpow(int a, int b) {
    int r = 1;
    for (; b > 0; b >>= 1, a = (int)a*a%hash_mod) 
        if (b&1) r = (int)r*a%hash_mod;
    return r;
}

const int b_N = 2;
bool init_ = 0;
array<int, b_N> bases;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

void init() {
    for (int i = 0; i < b_N; i++) {
        bases[i] = rint(2, hash_mod-1);
    }
}

// begin template //
using namespace std;
template<typename T> struct Hash2D {
    int n, m;
    vector<vector<int>> pref[b_N];
    vector<int> inv[b_N];
    void fadd(int& a, int b) {
        a += b;
        if (a >= hash_mod) a -= hash_mod;
    }
    void fsub(int& a, int b) {
        a -= b;
        if (a < 0) a += hash_mod;
    }
    Hash2D(const vector<T>& a) {
        if (!init_) init(), init_ = 1;
        n = a.size(), m = a[0].size();
        for (int d = 0; d < b_N; d++) {
            pref[d].resize(n, vector<int>(m));
            inv[d].resize(n*m);
            inv[d][n*m-1] = binpow(bases[d], (int)(n*m-1)*(hash_mod-2)%(hash_mod-1));
            for (int i = n*m-2; i >= 0; i--) 
                inv[d][i] = (int)inv[d][i+1] * bases[d] % hash_mod;
            for (int i = 0, base = 1; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    pref[d][i][j] = (int)((int)a[i][j]+300)*base%hash_mod;
                    if (i) fadd(pref[d][i][j], pref[d][i-1][j]);
                    if (j) fadd(pref[d][i][j], pref[d][i][j-1]);
                    if (i && j) fsub(pref[d][i][j], pref[d][i-1][j-1]);
                    base = (int)base*bases[d]%hash_mod;
                }
            }
        }
    }
    array<int, b_N> query(int x1, int y1, int x2, int y2) {
        array<int, b_N> ret;
        for (int i = 0; i < b_N; i++) {
            ret[i] = pref[i][x2][y2];
            if (x1) fsub(ret[i], pref[i][x1-1][y2]);
            if (y1) fsub(ret[i], pref[i][x2][y1-1]);
            if (x1 && y1) fadd(ret[i], pref[i][x1-1][y1-1]);
            ret[i] = (int)ret[i] * inv[i][x1*m+y1] % hash_mod;
        }
        return ret;
    }
};
// end template //

