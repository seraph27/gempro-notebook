#include <vector>
#include <string>

using namespace std;

// begin template //
vector<int> kmp(string s) {
	int n = s.size(), len = 0;
	vector<int> pre(n);
	for (int i = 1; i < n; i++) {
		while (len > 0 && s[i] != s[len]) len = pre[len - 1];
		if (s[i] == s[len]) len++;
		pre[i] = len;
	}
	return pre;
}
// end template //
