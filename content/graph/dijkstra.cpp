
#include <climits>
#include <queue>
#include <utility>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
vector<int> dijkstra(int s, vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();
    vector<int> dist(n, LLONG_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0; pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
// end template //

