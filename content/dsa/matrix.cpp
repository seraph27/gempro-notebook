
#include <array>
#include <cassert>

#define int long long
using namespace std;

// begin template //
using namespace std;
template<typename T, int N>
struct Matrix {
    array<array<T, N>, N> t;
    Matrix() : t{} {}
    Matrix operator * (const Matrix &other) const {
        Matrix res;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    res.t[i][k] += t[i][j] * other.t[j][k];
                }
            }
        }
        return res;
    }
    void operator *= (const Matrix &other) {
        *this = *this * other;
    }
    Matrix operator ^ (int k) const {
        assert(k >= 0);
        Matrix res, base = *this;
        for (int i = 0; i < N; i++) res.t[i][i] = 1;
        while (k) {
            if (k&1) res *= base;
            base *= base;
            k >>= 1;
        }
        return res;
    }
    void operator ^= (int k) {
        *this = *this ^ k;
    }
};
// end template //

