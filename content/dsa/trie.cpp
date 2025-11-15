#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
struct Trie {
    struct node {
        vector<int> next;
        bool is_end;
        int count;
        node() : next(26, -1), is_end(false), count(0) {}
    };
    vector<node> t;
    
    Trie() {
        t.emplace_back();
    }
    
    void insert(const string &s) {
        int v = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (t[v].next[idx] == -1) {
                t[v].next[idx] = t.size();
                t.emplace_back();
            }
            v = t[v].next[idx];
            t[v].count++;
        }
        t[v].is_end = true;
    }
    
    bool search(const string &s) {
        int v = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (t[v].next[idx] == -1) return false;
            v = t[v].next[idx];
        }
        return t[v].is_end;
    }
    
    bool starts_with(const string &s) {
        int v = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (t[v].next[idx] == -1) return false;
            v = t[v].next[idx];
        }
        return true;
    }
    
    int count_prefix(const string &s) {
        int v = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (t[v].next[idx] == -1) return 0;
            v = t[v].next[idx];
        }
        return t[v].count;
    }
};
// end template //

