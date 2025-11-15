#include <algorithm>
#include <numeric>
#include <stack>
#include <utility>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
struct RollbackDSU {
    vector<int> par, sz;
    stack<pair<int, int>> history;
    
    RollbackDSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    
    int root(int x) {
        while (par[x] != x) x = par[x];
        return x;
    }
    
    bool merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        history.push({y, x});
        par[y] = x;
        sz[x] += sz[y];
        return true;
    }
    
    void rollback() {
        if (history.empty()) return;
        auto [y, x] = history.top();
        history.pop();
        sz[x] -= sz[y];
        par[y] = y;
    }
    
    int checkpoint() {
        return history.size();
    }
    
    void rollback_to(int checkpoint_size) {
        while ((int)history.size() > checkpoint_size) {
            rollback();
        }
    }
};
// end template //

