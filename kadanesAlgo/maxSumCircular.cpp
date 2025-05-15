#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        int max_kadane = nums[0], current_max = 0;
        int min_kadane = nums[0], current_min = 0;

        for (int num : nums) {
            total_sum += num;
            current_max = max(num, current_max + num);
            max_kadane = max(max_kadane, current_max);
            current_min = min(num, current_min + num);
            min_kadane = min(min_kadane, current_min);
        }
        if (max_kadane < 0)
            return max_kadane;

        return max(max_kadane, total_sum - min_kadane);
    }
};



int main() {

    return 0;
}