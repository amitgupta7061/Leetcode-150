#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>& price, int ind, int txns, bool buy, vector<vector<vector<int>>>& dp, int k) {
        if (ind >= price.size() || txns >= k) return 0;

        if (dp[ind][txns][buy] != -1) return dp[ind][txns][buy];

        int profit = 0;
        if (buy) {
            profit = max(-price[ind] + f(price, ind + 1, txns, false, dp, k),
                                       f(price, ind + 1, txns, true, dp, k));
        } else {
            profit = max(price[ind] + f(price, ind + 1, txns + 1, true, dp, k),
                                      f(price, ind + 1, txns, false, dp, k));
        }

        return dp[ind][txns][buy] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return f(prices, 0, 0, true, dp, k);
    }
};



int main() {

    return 0;
}