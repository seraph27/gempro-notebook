

#include <algorithm>
#include <numeric>
#include <vector>

// begin template //
using namespace std;
struct DSU {
	vector<int> par, cnt;
	DSU(int n): par(n), cnt(n) {
		iota(par.begin(), par.end(), 0);
	}
	int root(int x) {
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}
	bool merge(int x, int y) {
		x = root(x), y = root(y);
		if (x == y) return false;
		if (cnt[x] < cnt[y]) swap(x, y);
		cnt[x] += cnt[y], par[y] = x;
		return true;
	}
};
// end template //
