
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
template<typename Elem>
struct RerootDP {
    struct elem {
        // Define your element structure here
    };
    Elem E() {
        // Return identity element
    }
    Elem merge(Elem x, Elem y) {
        // Merge two elements
    }
    Elem add_vertex(Elem x, int v) {
        // Add vertex to element
    }
    int n;
    vector<vector<int>> adj;
    RerootDP(int n_, const vector<vector<int>> &adj_) : n{n_}, adj{adj_} {}
    vector<Elem> solve() {
        vector<int> ord(n), p(n+1, -1);
        vector<Elem> dp(n+1, E()), rev_dp(n+1, E());
        auto dfs = [&, idx = 0](auto&& s, int v) mutable -> void {
            ord[idx++] = v;
            for (int u : adj[v]) {
                p[u] = v;
                adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
                s(s, u);
            }
        };
        dfs(dfs, 0);
        for (int i = n-1; i >= 0; i--) {
            int v = ord[i];
            for (int u : adj[v]) dp[v] = merge(dp[v], dp[u]);
            dp[v] = add_vertex(dp[v], v);
        }
        for (int v : ord) {
            const int N = adj[v].size();
            vector<Elem> pref(N+1, E()), suff(N+1, E());
            if (p[v] != -1) pref[0] = rev_dp[v];
            for (int i = 0; i < N; i++) {
                pref[i+1] = suff[i] = dp[adj[v][i]];
            }
            for (int i = 1; i <= N; i++) pref[i] = merge(pref[i-1], pref[i]);
            for (int i = N-1; i >= 0; i--) suff[i] = merge(suff[i], suff[i+1]);
            for (int i = 0; i < N; i++) {
                rev_dp[adj[v][i]] = add_vertex(merge(pref[i], suff[i+1]), v);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int v : adj[i]) {
                rev_dp[i] = merge(rev_dp[i], dp[v]);
            }
            rev_dp[i] = add_vertex(rev_dp[i], i);
        }
        return rev_dp;
    }
};
// end template //

