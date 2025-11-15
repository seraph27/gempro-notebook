
#include <algorithm>
#include <cassert>
#include <vector>

#define int long long
#define ar array

using namespace std;

// begin template //
using namespace std;
struct LinkCutTree {
    struct node {
        int p, c[2];
        bool rev;
        node() : p{}, c{}, rev{} {}
    };
    vector<node> a;
    LinkCutTree(int n) : a(n+1) {}
    void prop(int i) {
        node& v = a[i];
        if (!v.rev) return;
        swap(v.c[0], v.c[1]);
        if (v.c[0]) a[v.c[0]].rev ^= 1;
        if (v.c[1]) a[v.c[1]].rev ^= 1;
        v.rev = 0;
    }
    int side(int i) {
        node& v = a[i];
        if (!v.p) return -1;
        for (int j = 0; j < 2; j++) {
            if (a[v.p].c[j] == i) return j;
        }
        return -1;
    }
    bool root(int i) {
        return side(i) < 0;
    }
    void link_node(int x, int y, int d) {
        if (y) a[y].p = x;
        if (d >= 0) a[x].c[d] = y;
    }
    void rotate(int v) {
        assert(!root(v));
        int x = side(v), p = a[v].p;
        link_node(a[p].p, v, side(p));
        link_node(p, a[v].c[x^1], x);
        link_node(v, p, x^1);
    }
    void splay(int i) {
        while (!root(i) && !root(a[i].p)) {
            prop(a[a[i].p].p);
            prop(a[i].p);
            prop(i);
            rotate(side(i) == side(a[i].p) ? a[i].p : i);
            rotate(i);
        }
        if (!root(i)) prop(a[i].p), prop(i), rotate(i);
        prop(i);
    }
    void access(int i) {
        int orig = i;
        for (int lst = 0; i; i = a[i].p) {
            splay(i);
            a[i].c[1] = lst;
            lst = i;
        }
        splay(orig); 
        assert(!a[orig].c[1]);
    }
    void make_root(int i) {
        access(i);
        a[i].rev ^= 1;
        access(i);
        assert(!a[i].c[0]);
        assert(!a[i].c[1]);
    }
    void link(int x, int y) {
        make_root(x);
        access(y);
        assert(!a[x].c[0]);
        link_node(x, y, 0);
    }
    void cut(int x, int y) {
        make_root(x);
        access(y);
        a[a[y].c[0]].p = 0;
        a[y].c[0] = 0;
    }
    int lca(int x, int y) {
        if (x == y) return x;
        access(x); access(y);
        if (!a[x].p) return 0;
        splay(x);
        return a[x].p ? y : x;
    }
    bool connected(int x, int y) {
        return lca(x, y);
    }
};
// end template //

