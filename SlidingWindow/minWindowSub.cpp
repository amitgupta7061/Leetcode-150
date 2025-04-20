#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (char c : t) map[c]++;

        int i = 0, j = 0, cnt = t.size(), minLen = INT_MAX, start = 0;

        while (j < s.size()) {
            if (map[s[j]] > 0) cnt--;
            map[s[j]]--;
            j++;

            while (cnt == 0) {
                if (j - i < minLen) {
                    minLen = j - i;
                    start = i;
                }
                map[s[i]]++;
                if (map[s[i]] > 0) cnt++;
                i++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};


int main() {

    return 0;
}