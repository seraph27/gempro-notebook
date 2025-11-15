
#include <chrono>
#include <random>
#include <utility>

#define int long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// begin template //
using namespace std;
struct Treap {
    int val, pri, size;
    Treap *l, *r;
    Treap(int x) : val(x), pri(rng()), size(1), l(nullptr), r(nullptr) {}
    ~Treap() {
        delete l, delete r;
    }
};
int size(Treap* x) {
    return x ? x->size : 0;
}
Treap* upd(Treap* x) {
    x->size = size(x->l) + size(x->r) + 1;
    return x;
}
pair<Treap*, Treap*> split(Treap* v, int x, int add = 0) {
    if (!v) return {v, v};
    int left_size = size(v->l);
    if (left_size + add < x) {
        auto res = split(v->r, x, add + left_size + 1);
        v->r = res.first;
        return {upd(v), res.second};
    }
    else {
        auto res = split(v->l, x, add);
        v->l = res.second;
        return {res.first, upd(v)};
    }
}
Treap* merge(Treap* l, Treap* r) {
    if (!l) return r;
    if (!r) return l;
    if (l->pri < r->pri) {
        l->r = merge(l->r, r);
        return upd(l);
    }
    else {
        r->l = merge(l, r->l);
        return upd(r);
    }
}
// end template //

