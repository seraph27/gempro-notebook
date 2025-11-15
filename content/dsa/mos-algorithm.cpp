
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
// a is array size, q is number of queries
// queries[i] = {L, R, idx} where idx is the original index
void mo_algorithm(int a, vector<array<int, 3>>& queries, 
                  function<void(int)> add, function<void(int)> remove,
                  function<void(int)> process_query) {
    const int block = max(1LL, (int)round((double)a/sqrt(queries.size())));
    auto cmp = [&](const array<int, 3> &x, const array<int, 3> &y) {
        int A = x[0]/block, B = y[0]/block;
        if (A != B) return A < B;
        return A&1 ? x[1] > y[1] : x[1] < y[1];
    };
    sort(queries.begin(), queries.end(), cmp);
    int l = 0, r = -1;
    for (auto [ql, qr, idx] : queries) {
        while (l > ql) add(--l);
        while (r < qr) add(++r);
        while (l < ql) remove(l++);
        while (r > qr) remove(r--);
        process_query(idx);
    }
}
// end template //

