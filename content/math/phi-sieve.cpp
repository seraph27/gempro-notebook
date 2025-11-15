
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
const int N = 500005;
vector<int> phi(N+1), primes;
vector<bool> pr(N+1, true);
void init_phi() {
    phi[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (pr[i]) {
            primes.emplace_back(i);
            phi[i] = i-1;
        }
        for (int p : primes) {
            if (i*p > N) break;
            pr[i*p] = false;
            if (i%p == 0) {
                phi[i*p] = phi[i] * p;
                break;
            }
            phi[i*p] = phi[i] * (p - 1);
        }
    }
}
// end template //

