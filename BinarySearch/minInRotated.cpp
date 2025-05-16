#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int pivot = -1, n = nums.size(), low = 0, high = n-1;
        if(n == 2) return min(nums[0], nums[1]);
        while(low <= high){
            int mid = low + (high-low) / 2;
            if(mid == 0) low = mid + 1;
            else if(mid == n-1) high = mid - 1;
            else if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]){
                pivot = mid;
                break;
            }
            else if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
                pivot = mid+1;
                break;
            }
            else if(nums[mid] > nums[high]) low = mid + 1;
            else high = mid - 1;
        }
        if(pivot == -1) return nums[0];
        return nums[pivot];
    }
};

int main() {

    return 0;
}