#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(string &s, int ind, unordered_set<string> &dict, vector<int> &dp){
        if(ind >= s.length()) return true;
        if(dp[ind] != -1) return dp[ind];
        if(dict.count(s)) return true;
        for(int len = 0; len < s.length(); ++len){
            if(dict.count(s.substr(ind, len))){
                if(f(s, ind+len, dict, dp)) return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return f(s, 0, dict, dp);
    }
};

int main() {

    return 0;
}