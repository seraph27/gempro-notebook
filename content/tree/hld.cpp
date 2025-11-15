#include <algorithm>
#include <functional>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
struct HLD {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, size;
    
    HLD(int n_, const vector<vector<int>> &adj_) : n(n_), adj(adj_), 
        parent(n), depth(n), heavy(n, -1), head(n), pos(n), size(n) {
        timer = 0;
        dfs(0, -1);
        decompose(0, 0);
    }
    
    int dfs(int v, int p) {
        parent[v] = p;
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        size[v] = 1;
        int max_size = 0;
        
        for (int u : adj[v]) {
            if (u == p) continue;
            int subtree_size = dfs(u, v);
            size[v] += subtree_size;
            if (subtree_size > max_size) {
                max_size = subtree_size;
                heavy[v] = u;
            }
        }
        return size[v];
    }
    
    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = timer++;
        if (heavy[v] != -1) {
            decompose(heavy[v], h);
        }
        for (int u : adj[v]) {
            if (u != parent[v] && u != heavy[v]) {
                decompose(u, u);
            }
        }
    }
    
    // Query path from u to v
    // op: binary operation (e.g., max, min, +). res should be initialized with identity element.
    int query_path(int u, int v, function<int(int, int)> op, int identity = 0) {
        int res = identity; // Identity: 0 for sum, -inf for max, +inf for min
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            res = op(res, query_range(pos[head[u]], pos[u]));
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res = op(res, query_range(pos[u], pos[v]));
        return res;
    }
    
    int query_range(int l, int r) {
        // Implement with segment tree or Fenwick tree
        // This is a placeholder
        return 0;
    }
};
// end template //

