#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i] > nums[i-1] and nums[i] > nums[i+1]) return i;
        }
        return nums[0] > nums[nums.size()-1]? 0 : nums.size()-1;
    }
};

int main() {

    return 0;
}