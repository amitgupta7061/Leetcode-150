#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<int> &nums, int ind, vector<vector<int>> &result){
        if(ind == nums.size() - 1){
            result.push_back(nums); return;
        }
        for(int i = ind; i < nums.size(); i++){
            swap(nums[i], nums[ind]);
            f(nums, ind+1, result);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        f(nums, 0, result);
        return result;
    }
};

int main() {

    return 0;
}