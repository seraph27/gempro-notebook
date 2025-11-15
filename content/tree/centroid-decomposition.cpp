#include <algorithm>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
struct CentroidDecomposition {
    int n;
    vector<vector<int>> adj;
    vector<bool> removed;
    vector<int> size, parent;
    
    CentroidDecomposition(int n_, const vector<vector<int>> &adj_) 
        : n(n_), adj(adj_), removed(n, false), size(n), parent(n, -1) {}
    
    void dfs_size(int v, int p) {
        size[v] = 1;
        for (int u : adj[v]) {
            if (u == p || removed[u]) continue;
            dfs_size(u, v);
            size[v] += size[u];
        }
    }
    
    int find_centroid(int v, int p, int total) {
        for (int u : adj[v]) {
            if (u == p || removed[u]) continue;
            if (size[u] > total / 2) {
                return find_centroid(u, v, total);
            }
        }
        return v;
    }
    
    void decompose(int v, int p) {
        dfs_size(v, -1);
        int centroid = find_centroid(v, -1, size[v]);
        removed[centroid] = true;
        parent[centroid] = p;
        
        for (int u : adj[centroid]) {
            if (!removed[u]) {
                decompose(u, centroid);
            }
        }
    }
    
    void build() {
        decompose(0, -1);
    }
};
// end template //

