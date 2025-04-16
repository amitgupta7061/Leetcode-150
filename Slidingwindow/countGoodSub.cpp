#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int i = 0 , j = 0, n = nums.size(), pairCnt = 0;
        long long ans = 0;
        while(j < n){
            pairCnt += map[nums[j]];
            map[nums[j]]++;
            while(i < n and pairCnt >= k){
                ans += n - j;
                map[nums[i]]--;
                pairCnt -= map[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};


int main() {

    return 0;
}