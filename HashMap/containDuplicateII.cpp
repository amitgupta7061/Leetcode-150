#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < nums.size(); i++){
            if(map.count(nums[i])){
                for(auto it : map[nums[i]]){
                    if(abs(it - i) <= k) return true;
                }
            }
            map[nums[i]].push_back(i);
        }
        return false;
    }
};

int main() {

    return 0;
}