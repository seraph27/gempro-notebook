
#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
template<typename T> struct Dinic {
    struct edge {
        int u;
        T cap, flow;
        edge(int u_, T cap_) : u(u_), cap(cap_), flow(0) {}
    };
    vector<edge> edges;
    vector<vector<int>> adj;
    vector<int> level, nxt;
    Dinic(int n) : adj(n), level(n), nxt(n) {}
    void add(int u, int v, T cap) {
        int m = (int)edges.size();
        adj[u].emplace_back(m), adj[v].emplace_back(m+1);
        edges.emplace_back(v, cap);
        edges.emplace_back(u, 0);
    }
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q({s});
        level[s] = 0;
        while (q.size()) {
            int v = q.front(); q.pop();
            for (int id : adj[v]) {
                if (edges[id].flow == edges[id].cap) continue;
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
        while (bfs(s, t)) {
            fill(nxt.begin(), nxt.end(), 0);
            while (T tmp = dfs(s, t, numeric_limits<T>::max())) {
                ret += tmp;
            }
        }
        return ret;
    }
    vector<int> cut(int s) {
        vector<bool> vis(level.size());
        vector<int> seen;
        queue<int> q;
        q.push(s);
        while (q.size()) {
            int v = q.front(); q.pop();
            seen.emplace_back(v);
            for (int id : adj[v]) {
                auto [u, cap, flow] = edges[id];
                if (flow < cap && !vis[u]) {
                    q.push(u);
                    vis[u] = 1;
                }
            }
        }
        return seen;
    }
};
// end template //

