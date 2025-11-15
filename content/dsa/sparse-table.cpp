
#include <iterator>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
template<typename it, typename bin_op>
struct SparseTable {
    using T = typename remove_reference<decltype(*std::declval<it>())>::type;
    vector<vector<T>> t; 
    bin_op F;
 
    SparseTable(it first, it last, bin_op op) : t(1), F(op) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < (int)t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = F(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }
 
    T query(int l, int r) {
        int h = 31 - __builtin_clz(r-l+1);
        return F(t[h][l], t[h][r-(1<<h)+1]);
    }
};
// end template //

