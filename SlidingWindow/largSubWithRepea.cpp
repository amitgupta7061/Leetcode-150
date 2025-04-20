#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> visited(256, -1);
        int l = 0, r = 0, max_len = 0, n = s.length();
        while(r < n){
            if(visited[s[r]] != -1){
                if(visited[s[r]] >= l) l = visited[s[r]] + 1;
            }
            max_len = max(max_len, r - l + 1);
            visited[s[r]] = r;
            r++;
        }
        return max_len;
    }
};

int main() {

    return 0;
}