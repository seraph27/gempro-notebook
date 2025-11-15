#include <algorithm>
#include <vector>

#define int long long
using namespace std;

// begin template //
using namespace std;
// Manacher's Algorithm: finds longest palindromic substring
// Returns array where d1[i] = length of odd palindrome centered at i
// d2[i] = length of even palindrome centered between i-1 and i
pair<vector<int>, vector<int>> manacher(const string &s) {
    int n = s.size();
    vector<int> d1(n), d2(n);
    
    // Odd length palindromes
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    
    // Even length palindromes
    l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
    
    return {d1, d2};
}

// Get longest palindromic substring
string longest_palindrome(const string &s) {
    auto [d1, d2] = manacher(s);
    int max_len = 0, start = 0;
    
    for (int i = 0; i < (int)s.size(); i++) {
        int len1 = 2 * d1[i] - 1;
        int len2 = 2 * d2[i];
        if (len1 > max_len) {
            max_len = len1;
            start = i - d1[i] + 1;
        }
        if (len2 > max_len) {
            max_len = len2;
            start = i - d2[i];
        }
    }
    
    return s.substr(start, max_len);
}
// end template //

