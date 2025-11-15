

#include <vector>

const int mod = 1e9+7;

// begin template //
using namespace std;
// Stirling numbers of the first kind: s(n,k) = number of permutations of n elements with k cycles
vector<vector<int>> stirling1(int n) {
    vector<vector<int>> s(n+1, vector<int>(n+1));
    s[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = (s[i-1][j-1] + (i-1) * s[i-1][j]) % mod;
        }
    }
    return s;
}

// Stirling numbers of the second kind: S(n,k) = number of ways to partition n elements into k non-empty sets
vector<vector<int>> stirling2(int n) {
    vector<vector<int>> s(n+1, vector<int>(n+1));
    s[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = (s[i-1][j-1] + j * s[i-1][j]) % mod;
        }
    }
    return s;
}
// end template //

