#include <algorithm>
#include <string>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
// Suffix Array: builds sorted array of all suffixes
// sa[i] = starting index of i-th smallest suffix
// lcp[i] = longest common prefix between sa[i] and sa[i+1]
vector<int> build_suffix_array(const string &s) {
    int n = s.size();
    vector<int> sa(n), rank(n), new_rank(n);
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = s[i];
    }
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);
        new_rank[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            new_rank[sa[i]] = new_rank[sa[i-1]] + cmp(sa[i-1], sa[i]);
        }
        rank = new_rank;
    }
    return sa;
}

// LCP array: lcp[i] = LCP between suffix starting at sa[i] and sa[i+1]
vector<int> build_lcp(const string &s, const vector<int> &sa) {
    int n = s.size();
    vector<int> lcp(n), rank(n);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if (k > 0) k--;
    }
    return lcp;
}
// end template //

