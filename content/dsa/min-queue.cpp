
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
template <class T> struct MinQueue {
    deque<T> q;
    T min() const { return q.front(); }
    int size() const { return q.size(); }
    void push(const T &val) {
        while (!q.empty() && q.back() > val) q.pop_back();
        q.push_back(val);
    }
    void pop(const T &rem) {
        if (!q.empty() && q.front() == rem) q.pop_front();
    }
};
// end template //

