

#define int long long
using namespace std;

// begin template //
int choose(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    long double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
// end template //

