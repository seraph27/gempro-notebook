#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
template<class S, S (*op)(S, S), S (*e)()>
struct PersistentSegtree {
    struct node {
        S val;
        int l, r;
        node() : val(e()), l(-1), r(-1) {}
        node(S v) : val(v), l(-1), r(-1) {}
    };
    vector<node> t;
    vector<int> roots;
    int n;
    
    PersistentSegtree(int N) : n(N) {
        roots.push_back(build(0, n));
    }
    
    int build(int l, int r) {
        int id = t.size();
        t.emplace_back(e());
        if (l + 1 == r) return id;
        int mid = (l + r) / 2;
        t[id].l = build(l, mid);
        t[id].r = build(mid, r);
        t[id].val = op(t[t[id].l].val, t[t[id].r].val);
        return id;
    }
    
    int set(int i, S value, int root_id) {
        return set(i, value, root_id, 0, n);
    }
    
    int set(int i, S value, int v, int l, int r) {
        if (l + 1 == r) {
            int id = t.size();
            t.emplace_back(value);
            return id;
        }
        int mid = (l + r) / 2;
        int id = t.size();
        t.emplace_back();
        if (i < mid) {
            t[id].l = set(i, value, t[v].l, l, mid);
            t[id].r = t[v].r;
        } else {
            t[id].l = t[v].l;
            t[id].r = set(i, value, t[v].r, mid, r);
        }
        t[id].val = op(t[t[id].l].val, t[t[id].r].val);
        return id;
    }
    
    S query(int l, int r, int root_id) {
        return query(l, r, root_id, 0, n);
    }
    
    S query(int ql, int qr, int v, int l, int r) {
        if (ql >= r || qr <= l) return e();
        if (ql <= l && r <= qr) return t[v].val;
        int mid = (l + r) / 2;
        return op(query(ql, qr, t[v].l, l, mid), query(ql, qr, t[v].r, mid, r));
    }
    
    int new_version(int root_id) {
        roots.push_back(root_id);
        return roots.size() - 1;
    }
};
// end template //

