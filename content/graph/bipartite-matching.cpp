
#include <array>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
struct BipartiteMatching {
    vector<vector<int>> adj;
    vector<int> mt;
    vector<bool> vis;
    int n, m;
    BipartiteMatching(int _n, int _m) : adj(_n+1), mt(_m+1, -1), vis(_n+1), n(_n), m(_m) {}
    void add_edge(int x, int y) {
        adj[x].emplace_back(y);
    }
    bool dfs(int v) {
        if (vis[v]) return 0;
        vis[v] = 1;
        for (int u : adj[v]) {
            if (mt[u] == -1 || dfs(mt[u])) {
                mt[u] = v; return 1;
            }
        }
        return 0;
    }
    vector<array<int, 2>> get_matching() {
        int cnt = 0;
        for (int v = 1; v <= n; v++) {
            if (v > 1) fill(vis.begin(), vis.end(), 0);
            cnt += dfs(v);
        }
        vector<array<int, 2>> res(cnt);
        for (int i = 1, c = 0; i <= m; i++) if (mt[i] != -1) {
            res[c++] = {mt[i], i};
        }
        return res;
    }
};
// end template //

