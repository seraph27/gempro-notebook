#include <map>
#include <set>
#include <vector>
#include <functional>

#define int long long
using namespace std;

// begin template //
using namespace std;
// Grundy Numbers (Nim Game)
// Grundy number of a position = mex of Grundy numbers of all reachable positions
// mex (minimum excludant) = smallest non-negative integer not in the set

int mex(const set<int> &s) {
    int res = 0;
    for (int x : s) {
        if (x == res) res++;
        else break;
    }
    return res;
}

int mex(const vector<int> &v) {
    set<int> s(v.begin(), v.end());
    return mex(s);
}

// Basic Grundy number computation for a position
int grundy(int pos, function<vector<int>(int)> get_moves) {
    if (pos == 0) return 0; // terminal position
    set<int> reachable;
    for (int next : get_moves(pos)) {
        reachable.insert(grundy(next, get_moves));
    }
    return mex(reachable);
}

// Grundy number for Nim: grundy(n) = n
int grundy_nim(int n) {
    return n;
}

// Grundy number for subtraction game: can remove 1, 2, or 3 stones
int grundy_subtraction(int n) {
    return n % 4;
}

// Grundy number for take-away game: can remove k stones where k is in allowed set
int grundy_takeaway(int n, const vector<int> &allowed) {
    if (n == 0) return 0;
    set<int> reachable;
    for (int k : allowed) {
        if (k <= n) {
            reachable.insert(grundy_takeaway(n - k, allowed));
        }
    }
    return mex(reachable);
}

// Advanced: Grundy number for composite games (XOR of component games)
// If game splits into independent components, grundy = XOR of component grundies
int grundy_composite(const vector<int> &component_grundies) {
    int res = 0;
    for (int g : component_grundies) {
        res ^= g;
    }
    return res;
}

// Advanced: Periodicity detection for Grundy numbers
// Many games have periodic Grundy sequences
vector<int> grundy_periodic(int max_n, function<int(int)> compute_grundy) {
    vector<int> grundies(max_n + 1);
    for (int i = 0; i <= max_n; i++) {
        grundies[i] = compute_grundy(i);
    }
    // Detect period: find smallest p such that grundies[i] == grundies[i+p] for large i
    return grundies;
}

// Advanced: Grundy number with memoization for complex games
map<int, int> grundy_memo;
int grundy_memoized(int pos, function<vector<int>(int)> get_moves) {
    if (grundy_memo.count(pos)) return grundy_memo[pos];
    if (pos == 0) return grundy_memo[pos] = 0;
    set<int> reachable;
    for (int next : get_moves(pos)) {
        reachable.insert(grundy_memoized(next, get_moves));
    }
    return grundy_memo[pos] = mex(reachable);
}
// end template //

