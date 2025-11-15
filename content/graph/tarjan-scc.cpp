#include <algorithm>
#include <stack>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
vector<vector<int>> tarjan_scc(int n, const vector<vector<int>> &adj) {
    vector<int> tin(n, -1), low(n, -1);
    vector<bool> on_stack(n, false);
    stack<int> st;
    int timer = 0;
    vector<vector<int>> components;
    
    function<void(int)> dfs = [&](int v) {
        tin[v] = low[v] = timer++;
        st.push(v);
        on_stack[v] = true;
        
        for (int u : adj[v]) {
            if (tin[u] == -1) {
                dfs(u);
                low[v] = min(low[v], low[u]);
            } else if (on_stack[u]) {
                low[v] = min(low[v], tin[u]);
            }
        }
        
        if (low[v] == tin[v]) {
            vector<int> comp;
            while (true) {
                int u = st.top();
                st.pop();
                on_stack[u] = false;
                comp.push_back(u);
                if (u == v) break;
            }
            components.push_back(comp);
        }
    };
    
    for (int i = 0; i < n; i++) {
        if (tin[i] == -1) dfs(i);
    }
    return components;
}
// end template //

