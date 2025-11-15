#include <algorithm>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
vector<int> articulation_points(int n, const vector<vector<int>> &adj) {
    vector<int> tin(n, -1), low(n, -1);
    vector<bool> is_ap(n, false);
    int timer = 0;
    
    auto dfs = [&](auto&& self, int v, int p) -> void {
        tin[v] = low[v] = timer++;
        int children = 0;
        
        for (int u : adj[v]) {
            if (u == p) continue;
            if (tin[u] == -1) {
                children++;
                self(self, u, v);
                low[v] = min(low[v], low[u]);
                if (p != -1 && low[u] >= tin[v]) {
                    is_ap[v] = true;
                }
            } else {
                low[v] = min(low[v], tin[u]);
            }
        }
        
        if (p == -1 && children > 1) {
            is_ap[v] = true;
        }
    };
    
    for (int i = 0; i < n; i++) {
        if (tin[i] == -1) dfs(dfs, i, -1);
    }
    
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (is_ap[i]) result.push_back(i);
    }
    return result;
}
// end template //

