
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <queue>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
struct MinCostMaxFlow {
    int n;
    vector<vector<int>> cap, cost;
    vector<vector<int>> adj;
    MinCostMaxFlow(int _n) : n(_n), cap(n, vector<int>(n)), cost(n, vector<int>(n)), adj(n) {}
    void add_edge(int u, int v, int Cap, int Cost) {
        cap[u][v] = Cap, cost[u][v] = Cost, cost[v][u] = -Cost;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    array<int, 2> max_flow(int s, int t) {
        vector<int> dist(n), p(n);
        array<int, 2> ans{};
        while (1) {
            fill(dist.begin(), dist.end(), INT_MAX);
            queue<int> q;
            vector<bool> inq(n);
            q.push(s), dist[s] = 0, inq[s] = 1;
            while (q.size()) {
                int v = q.front(); q.pop();
                inq[v] = 0;
                for (int u : adj[v]) if (cap[v][u]) {
                    int w = cost[v][u];
                    if (dist[v] + w < dist[u]) {
                        dist[u] = dist[v] + w;
                        p[u] = v;
                        if (!inq[u]) {
                            inq[u] = 1;
                            q.push(u);
                        }
                    }
                }
            }
            if (dist[t] == INT_MAX) break;
            int min_cap = INT_MAX;
            int v = t;
            while (v != s) {
                int u = p[v];
                min_cap = min(min_cap, cap[u][v]);
                v = u;
            }
            v = t;
            while (v != s) {
                int u = p[v];
                cap[u][v] -= min_cap;
                cap[v][u] += min_cap;
                v = u;
            }
            ans[0] += min_cap, ans[1] += dist[t] * min_cap;
        }
        return ans;
    }
};
// end template //

