#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> dp;

    bool f(string &s1, string &s2, string &s3, int a, int b, int c) {
        if (c == s3.size()) {
            return a == s1.size() and b == s2.size();
        }

        string key = to_string(a) + "," + to_string(b);
        if (dp.count(key)) return dp[key];

        bool ok = false;
        if (a < s1.size() and s1[a] == s3[c]) {
            ok = ok or f(s1, s2, s3, a + 1, b, c + 1);
        }
        if (b < s2.size() and s2[b] == s3[c]) {
            ok = ok or f(s1, s2, s3, a, b + 1, c + 1);
        }

        return dp[key] = ok;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        return f(s1, s2, s3, 0, 0, 0);
    }
};


int main() {

    return 0;
}