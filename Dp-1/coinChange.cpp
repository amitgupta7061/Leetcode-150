#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &coins, int ind, int amount, vector<vector<int>> &dp){
        if(amount == 0) return 0;
        if(ind >= coins.size()) return 1e6;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int pick = 1e6;
        if(amount >= coins[ind]) pick = 1 + f(coins, ind, amount - coins[ind], dp);
        int notPick = f(coins, ind + 1, amount, dp);
        return dp[ind][amount] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int result = f(coins, 0, amount, dp);
        return result == 1e6 ? -1 : result;
    }
};

int main() {

    return 0;
}