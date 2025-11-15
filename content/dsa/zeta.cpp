
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
vector<int> subsetZeta(vector<int> a) {
	int n = a.size();
	for (int j = 1; j < n; j <<= 1)
		for (int i = 1; i < n; i++)
			if (i & j) a[i] += a[i ^ j];
	return a;
}
vector<int> subsetMobius(vector<int> a) {
	int n = a.size();
	for (int j = 1; j < n; j <<= 1)
		for (int i = 1; i < n; i++)
			if (i & j) a[i] -= a[i ^ j];
	return a;
}
vector<int> supersetZeta(vector<int> a) {
	int n = a.size();
	for (int j = 1; j < n; j <<= 1)
		for (int i = 1; i < n; i++)
			if (i & j) a[i ^ j] += a[i];
	return a;
}
vector<int> supersetMobius(vector<int> a) {
	int n = a.size();
	for (int j = 1; j < n; j <<= 1)
		for (int i = 1; i < n; i++)
			if (i & j) a[i ^ j] -= a[i];
	return a;
}
// end template //
