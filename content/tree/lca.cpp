
#include <algorithm>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
struct LCA {
    const int LOG;
    vector<vector<int>> up;
    vector<int> depth;
    LCA(int n, const vector<vector<int>> &adj, int root = 0) 
        : LOG(32 - __builtin_clz(n)), up(n, vector<int>(LOG)), depth(n) {
        auto dfs = [&](auto &&s, int v, int p) -> void {
            for (int u : adj[v]) if (u != p) {
                depth[u] = depth[v] + 1;
                up[u][0] = v;
                for (int i = 1; i < LOG; i++) {
                    up[u][i] = up[up[u][i-1]][i-1];
                }
                s(s, u, v);
            }
        };
        dfs(dfs, root, -1);
    }
    int lca(int x, int y) {
        if (depth[x] < depth[y]) swap(x, y);
        int K = depth[x] - depth[y];
        for (int i = 0; i < LOG; i++) if ((K>>i)&1) x = up[x][i];
        for (int i = LOG-1; i >= 0; i--) if (up[x][i] != up[y][i]) {
            x = up[x][i], y = up[y][i];
        }
        return x == y ? x : up[x][0];
    }
    int dist(int x, int y) {
        return depth[x] + depth[y] - 2 * depth[lca(x, y)];
    }
};
// end template //

