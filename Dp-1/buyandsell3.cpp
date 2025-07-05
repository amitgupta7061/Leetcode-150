#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &price, int ind, int cnt, bool buy, vector<vector<vector<int>>>& dp){
        if(ind >= price.size()) return 0;
        if(cnt >= 2) return 0;

        if(dp[ind][cnt][buy] != -1) return dp[ind][cnt][buy];

        int profit = 0;
        if(buy){
            profit = max(-price[ind] + f(price, ind+1, cnt, false, dp),f(price, ind+1, cnt, true, dp));
        } else {
            profit = max(price[ind] + f(price, ind+1, cnt+1, true, dp), f(price, ind+1, cnt, false, dp));
        }

        return dp[ind][cnt][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return f(prices, 0, 0, true, dp);
    }
};


int main() {

    return 0;
}