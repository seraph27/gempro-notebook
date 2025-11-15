#include <array>
#include <climits>
#include <utility>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
// Bellman-Ford: Shortest paths with negative edges, detects negative cycles
// edges: {u, v, weight}
// Returns {distances, has_negative_cycle}
pair<vector<int>, bool> bellman_ford(int n, int s, const vector<array<int, 3>> &edges) {
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    
    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // Check for negative cycles
    bool has_cycle = false;
    for (auto [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            has_cycle = true;
            break;
        }
    }
    
    return {dist, has_cycle};
}
// end template //

