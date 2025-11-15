
#include <algorithm>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
template <class T>
struct RangeUpdatePointQuery {
    const int N; 
    vector<T> tree;
    RangeUpdatePointQuery(int n) : N(1<<(32-__builtin_clz(max(1LL, n-1LL)))), tree(2*N) {}
    void update(int node, int nl, int nr, int ql, int qr, T v) {
        if (ql > nr || qr < nl) return;
        if (ql <= nl && nr <= qr) { 
            tree[node] += v;
            return;
        }
        int mid = (nl+nr)/2;
        update(node*2, nl, mid, ql, qr, v);
        update(node*2+1, mid+1, nr, ql, qr, v);
    }
    void update(int l, int r, T v) { update(1, 0, N-1, l, r, v); }
    T query(int pos) {
        T ret = 0;
        for (int i = pos+N; i > 0; i >>= 1) ret += tree[i];
        return ret;
    }
};
// end template //

