#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                int x = mid, y = mid;
                while(x >= 0 and nums[x] == target) x--;
                while(y < nums.size() and nums[y] == target) y++;
                return {x+1, y-1};
            } else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return {-1,-1};
    }
};

int main() {

    return 0;
}