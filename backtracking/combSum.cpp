#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<int>& cand, int ind, int k, vector<int> &temp, vector<vector<int>> &result){
        if(k == 0){
            result.push_back(temp);
            return;
        }
        if(k < 0 or ind >= cand.size()) return;
        if(k >= cand[ind]){
            temp.push_back(cand[ind]);
            f(cand, ind, k-cand[ind], temp, result);
            temp.pop_back();
        }
        f(cand, ind+1, k, temp, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        f(candidates, 0, target, temp, result);
        return result;
    }
};

int main() {

    return 0;
}