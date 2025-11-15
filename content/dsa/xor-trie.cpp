#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
struct XorTrie {
    struct node {
        int next[2];
        int count;
        node() : next{-1, -1}, count(0) {}
    };
    vector<node> t;
    static const int BITS = 30;
    
    XorTrie() {
        t.emplace_back();
    }
    
    void insert(int x) {
        int v = 0;
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (t[v].next[bit] == -1) {
                t[v].next[bit] = t.size();
                t.emplace_back();
            }
            v = t[v].next[bit];
            t[v].count++;
        }
    }
    
    void erase(int x) {
        int v = 0;
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            v = t[v].next[bit];
            t[v].count--;
        }
    }
    
    int max_xor(int x) {
        int v = 0, res = 0;
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int want = 1 - bit;
            if (t[v].next[want] != -1 && t[t[v].next[want]].count > 0) {
                res |= (1LL << i);
                v = t[v].next[want];
            } else {
                v = t[v].next[bit];
            }
        }
        return res;
    }
    
    int min_xor(int x) {
        int v = 0, res = 0;
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (t[v].next[bit] != -1 && t[t[v].next[bit]].count > 0) {
                v = t[v].next[bit];
            } else {
                res |= (1LL << i);
                v = t[v].next[1 - bit];
            }
        }
        return res;
    }
};
// end template //

