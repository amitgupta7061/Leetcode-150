#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums, int ind, int target, vector<vector<int>> &dp){
        if(target <= 0) return 0;
        if(ind >= nums.size()) return INT_MAX;
        if(dp[ind][target] != -1) return dp[ind][target];
        int take = f(nums, ind + 1, target - nums[ind], dp);
        if (take != INT_MAX) take += 1;
        int notTake = f(nums, ind + 1, target, dp);
        return dp[ind][target] = min(take, notTake);
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        int result = f(nums, 0, target, dp);
        return result == INT_MAX ? 0 : result;
    }
};

class Solution_2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0 , n = nums.size(), min_len = INT_MAX, sum = 0;
        for(int rght = 0; rght < n; rght++){
            sum += nums[rght];
            while(sum >= target){
                min_len = min(min_len, rght - left + 1);
                sum -= nums[left++];
            }
        }
        return min_len == INT_MAX? 0 : min_len;
    }
};

int main() {

    return 0;
}