#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        vector<string> result;
        for(int i = 0; i < nums.size(); i++) {
            int start = nums[i];
            while(i+1 < nums.size() && nums[i] + 1 == nums[i+1]) i++;
            if(start != nums[i]) {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            } else {
                result.push_back(to_string(start));
            }  
        }
        return result; 
    }
};

int main() {

    return 0;
}