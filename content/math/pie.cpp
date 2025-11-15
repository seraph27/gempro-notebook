#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
// Principle of Inclusion-Exclusion (PIE)
// Counts elements in union of sets: |A1 U A2 U ... U An|
// Formula: |U Ai| = sum|Ai| - sum|Ai & Aj| + sum|Ai & Aj & Ak| - ... + (-1)^(n+1)|A1 & ... & An|
int pie_union(const vector<int> &sizes) {
    int n = sizes.size();
    int res = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int cnt = __builtin_popcount(mask);
        int intersection = 1; // Adjust based on problem
        // For each set in mask, compute intersection
        // This is a template - modify based on problem
        res += (cnt % 2 == 1 ? 1 : -1) * intersection;
    }
    return res;
}

// General PIE: Count elements in exactly k sets
// |exactly k| = sum_{j=k}^n (-1)^(j-k) * C(j,k) * |at least j|
int pie_exactly_k(const vector<int> &at_least, int k) {
    int n = at_least.size();
    int res = 0;
    for (int j = k; j <= n; j++) {
        int sign = ((j - k) % 2 == 0) ? 1 : -1;
        int comb = 1; // C(j, k) - compute using combinatorics
        for (int i = 0; i < k; i++) {
            comb = comb * (j - i) / (i + 1);
        }
        res += sign * comb * at_least[j];
    }
    return res;
}

// PIE for counting: number of elements NOT in any of the sets
// |complement| = |universe| - |union|
int pie_complement(int universe_size, const vector<int> &sizes) {
    return universe_size - pie_union(sizes);
}
// end template //

