
#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
template<typename T> struct DinicScaling {
    struct edge {
        int u;
        T cap, flow;
        edge(int u_, T cap_) : u(u_), cap(cap_), flow(0) {}
    };
    vector<edge> edges;
    vector<vector<int>> adj;
    vector<int> level, nxt;
    DinicScaling(int n) : adj(n), level(n), nxt(n) {}
    void add(int u, int v, T cap) {
        int m = (int)edges.size();
        adj[u].emplace_back(m), adj[v].emplace_back(m+1);
        edges.emplace_back(v, cap);
        edges.emplace_back(u, 0);
    }
    bool bfs(int s, int t, int lim) {
        fill(level.begin(), level.end(), -1);
        queue<int> q({s});
        level[s] = 0;
        while (q.size()) {
            int v = q.front(); q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < lim) continue;
                int u = edges[id].u;
                if (!~level[u]) level[u] = level[v]+1, q.push(u);
            }
        }
        return ~level[t];
    }
    T dfs(int v, int t, T pushed) {
        if (!pushed || v == t) return pushed;
        for (; nxt[v] < (int)adj[v].size(); nxt[v]++) {
            int id = adj[v][nxt[v]];
            auto [u, cap, flow] = edges[id];
            if (level[u] != level[v] + 1) continue;
            if (T get = dfs(u, t, min(cap-flow, pushed))) {
                edges[id].flow += get;
                edges[id^1].flow -= get;
                return get;
            }
        }
        return 0;
    }
    T flow(int s, int t) {
        T ret = 0;
        for (int lim = 1 << 30; lim; lim >>= 1) {
            while (bfs(s, t, lim)) {
                fill(nxt.begin(), nxt.end(), 0);
                while (T tmp = dfs(s, t, numeric_limits<T>::max())) {
                    ret += tmp;
                }
            }
        }
        return ret;
    }
};
// end template //

