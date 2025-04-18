#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(map.count(rem)) return {map[rem], i};
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};


int main() {

    return 0;
}