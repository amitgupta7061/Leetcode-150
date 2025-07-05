#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(string &word1, string &word2, int l, int r, vector<vector<int>> &dp){
        if (l == word1.length()) return word2.length() - r;
        if (r == word2.length()) return word1.length() - l;

        if(dp[l][r] != -1) return dp[l][r];

        if(word1[l] == word2[r]){
            return dp[l][r] = f(word1, word2, l+1, r+1, dp);
        } else {
            int replace = 1 + f(word1, word2, l+1, r+1, dp);
            int insert  = 1 + f(word1, word2, l, r+1, dp);
            int remove  = 1 + f(word1, word2, l+1, r, dp);

            return dp[l][r] = min({replace, insert, remove});
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return f(word1, word2, 0, 0, dp);
    }
};

int main() {

    return 0;
}