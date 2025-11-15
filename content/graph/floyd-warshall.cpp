#include <algorithm>
#include <climits>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
// Floyd-Warshall: All-pairs shortest paths
// dist[i][j] = shortest distance from i to j
void floyd_warshall(vector<vector<int>> &dist) {
    int n = dist.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
// end template //

