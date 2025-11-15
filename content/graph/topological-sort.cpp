#include <queue>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
// Kahn's algorithm for topological sort
vector<int> topological_sort(int n, const vector<vector<int>> &adj) {
    vector<int> in_degree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            in_degree[j]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        result.push_back(v);
        
        for (int u : adj[v]) {
            in_degree[u]--;
            if (in_degree[u] == 0) {
                q.push(u);
            }
        }
    }
    
    // If result.size() != n, graph has cycle
    return result;
}
// end template //

